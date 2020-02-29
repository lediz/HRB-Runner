const isNative = require("./isNative.js");
const VarReference = require("./VarReference.js");
const HBDateTime = require("./HBDateTime.js");

/** @typedef HRBfunc A function from HRB file
 * @property {string} name the name of function
 * @property {ArrayBuffer} code the byte code
 * @property {function} definition the callable version
*/
/** @typedef HRBsymb A symbol define inside the HRB file
 * @property {string} name the name of function
 * @property {Number} scope scope flags
 * @property {Number} pcode if one... local?
 * @property {function} ptr the callable reference
*/

/** @readonly
 * @enum {number} */
var HB_FS = {
    PUBLIC    :0x0001, //
    STATIC    :0x0002, // visible only on HRB
    FIRST     :0x0004, // first of file
    INIT      :0x0008, // to call on init
    EXIT      :0x0010, // to call on exit (not used)
    MESSAGE   :0x0020, // class method
    MEMVAR    :0x0080, // not a function
    PCODEFUNC :0x0100, //
    LOCAL     :0x0200, //
    DYNCODE   :0x0400, //
    DEFERRED  :0x0800, //
    FRAME     :0x1000, //
    USED      :0x2000 //

}
/* scope flags
*/

/**
 * The hrb container
 * @param {Object} context destination context
 */
function HRB(context) {
    this.context = context || window;
    /** @type {HRBfunc[]} */
    this.functions=[];
    /** @type {HRBsymb[]} */
    this.symbols=[];
    this.statics = [];
}

/**
 *
 * @param {String} cPath
 * @param {function(Object)} onDone
 * @param {function(String)} onError
 */
HRB.prototype.download = function(cPath) {
    return new Promise((resolve,reject) => {
        var req = new XMLHttpRequest();
        req.responseType = 'arraybuffer';
        req.open("GET",cPath);
        req.send();
        req.onload = function(e) {
            if(req.status==200) {
                resolve(req.response)
            } else {
                onError("unable to load");
            }
        }
    }).then((v) => this.loadFromBuffer(v));
}

/**
 * @param {number} from
 * @param {number?} len
 * @returns {string}
 */
DataView.prototype.toStringANSI = function(from,len) {
    var r="";
    if(!len) len=this.byteLength-from;
    for (let i = 0; i < len; i++) {
        var v = this.getUint8(from+i);
        if(v==0) break;
        r+=String.fromCharCode(v);
    }
    return r;
}

/**
 * @param {ArrayBuffer} binHRB
 */
HRB.prototype.loadFromBuffer = function(binHRB) {
    return new Promise((resolve,reject) => {
        var view = new DataView(binHRB);
        // 0 4 @HRB header
        if(view.getUint8(0)!=192 || view.toStringANSI(1,3)!='HRB') {
            reject("not a HRB");
            return
        }
        // 4 2 DWORD version
        // 6 4 NSYMBOLS
        var version = view.getUint16(4, true);
        var nSymbols = view.getUint32(6, true);
        this.statics=[];
        this.symbols = [];
        var offset = 10;
        for (let i = 0; i < nSymbols; i++) {
            var name = view.toStringANSI(offset);
            offset+=name.length+1;
            var scope = view.getUint8(offset++);
            var pCode = view.getUint8(offset++);
            this.symbols.push({"name":name, "scope":scope, "pcode":pCode});
        }
        var nFunctions = view.getUint32(offset, true); offset+=4;
        this.functions = [];
        for (let i = 0; i < nFunctions; i++) {
            var name = view.toStringANSI(offset);
            offset+=name.length+1;
            var len = view.getUint32(offset,true); offset+=4;
            var code = binHRB.slice(offset,offset+len);
            offset+=len;
            this.functions.push({"name":name, "code":code });
        }
       resolve(this);
    });
}

/**
 * Search a symbol
 * @param {Object} context the object where search the symbol
 * @param {HRBsymb} symb the symbol to search
 * @param {Boolean} mustOK if true and it is not found spawns an exception, a warning otherwise
 */

function getSymbol(context, symb, mustOK) {
    if(symb.ptr) return symb.ptr;
    var name = symb.name;
    if(name.startsWith("_")) name = name.substring(1);
    var thisContext = context;
    while(thisContext) {
        if(name in thisContext) {
            var retVal = context[name];
            if(!symb.scope & HB_FS.MESSAGE )
                symb.ptr = retVal
            if(isNative(retVal)) console.warn(name + " native");
            if(typeof(retVal) == "function" || typeof(retVal) == "object")
                return retVal;
            else
                return name;
        }
        for (const key in thisContext) {
            if (thisContext.hasOwnProperty(key)) {//  && typeof(context[key]) == "function" ) {
                if(key.toUpperCase()==name) {
                    var retVal = context[key];
                    if(!symb.scope & HB_FS.MESSAGE )
                        symb.ptr = retVal;
                    if(isNative(retVal)) console.warn(name + " native");
                    if(retVal && (typeof(retVal) == "function" || typeof(retVal) == "object"))
                        return retVal;
                    else
                        return key;
                }
            }
        }
        if(symb.scope & HB_FS.MESSAGE ) {
            thisContext =  thisContext.__proto__
        } else {
            if(thisContext!=this.context) {
                thisContext = this.context;
                context = this.context;
            } else
                thisContext = null;
        }
    }
    if(mustOK)
        throw "symbol not found:" + name
    console.error("symbol not found:" + name);
    return undefined;
}

/**
 * emulate array definition of harbour
 * @param {Array<Number>} dims the size of array
 */
function generateArray(dims) {
    var ret = Array(dims[0]);
    if(dims.length>1) {
        var subDim = dims.slice(1);
        for (let i = 0; i < ret.length; i++) {
            ret[i]=generateArray(subDim);
        }
    }
    return ret;
}

// 71/181 codes impleme1nted
HRB.prototype.runCode = function(code,args,nLocals,nArgs) {
    var view = new DataView(code);
    var pCounter = 0;
    var stack = [];
    var locals = nLocals? new Array(nLocals) : [];
    var returnVal = undefined;
    var currLine; //debug purpose
    nArgs = nArgs || 0;

    stack.popValue = function() {
        var v=this.pop();
        if(v && typeof(v)=="object" && v.constructor==VarReference)
            v=v.value();
        return v;
    }

    while(true) {
        var pCode = view.getUint8(pCounter);
        switch(pCode) {
            case   0 :               /* HB_P_AND performs the logical AND of two latest stack values, removes them and places result */
                stack.push(stack.popValue()&&stack.popValue());
                pCounter+=1;
                break;
            case   1 : {            /* HB_P_ARRAYPUSH places on the virtual machine stack an array element */
                let idx = stack.popValue();
                let arr = stack.popValue();
                stack.push(arr[idx-1]);
                pCounter+=1;
                break; }
            case   2 : {             /* HB_P_ARRAYPOP pops a value from the eval stack into an array element */
                let idx = stack.popValue()-1;
                let arr = stack.popValue();
                let val = stack.popValue();
                arr[idx] = val; //the array is always reference in js
                pCounter+=1;
                break; }
            case   3 :  {            /* HB_P_ARRAYDIM instructs the virtual machine to build an array with some specific dimensions */
                let n = view.getUint16(pCounter+1,true);
                stack.push(generateArray(stack.splice(stack.length-n)));
                pCounter+=3;
                break; }
            case   4 : {             /* HB_P_ARRAYGEN instructs the virtual machine to build an array and load element from the stack */
                let n = view.getUint16(pCounter+1,true);
                stack.push(stack.splice(stack.length-n));
                pCounter+=3;
                break; }
            case   5 :                 /* HB_P_EQUAL check if the latest two values on the stack are equal, removing them and leaving the result */
            case   8 :          /* HB_P_EXACTLYEQUAL check if the latest two values on the stack are exactly equal, removing them and leaving the result */
                stack.push(stack.popValue()==stack.popValue());
                pCounter+=1;
                break;
            case   6 :              /* HB_P_ENDBLOCK end of a codeblock definition */
            case   7 :               /* HB_P_ENDPROC instructs the virtual machine to end execution */
                return returnVal;
            case   9 :                 /* HB_P_FALSE pushes false on the virtual machine stack */
                stack.push( false );
                pCounter+=1;
                break;
            case  11 :              /* HB_P_FUNCTION instructs the virtual machine to execute a function saving its result */
            case  12 :         /* HB_P_FUNCTIONSHORT instructs the virtual machine to execute a function saving its result */
            case  19 :                    /* HB_P_DO instructs the virtual machine to execute a function discarding its result */
            case  20 : {              /* HB_P_DOSHORT instructs the virtual machine to execute a function discarding its result */
                let nParam = pCode&1? view.getUint16(pCounter+1,true) : view.getUint8(pCounter+1,true);
                let params = stack.splice(stack.length-nParam);
                let ret = stack.popValue().apply(undefined,params);
                if(pCode<15)
                    stack.push(ret);
                pCounter += pCode&1? 3 : 2;
                break; }
            case  13 :                 /* HB_P_FRAME instructs the virtual machine about how many parameters and locals a function uses */
                locals = Array(view.getUint8(pCounter+1));
                nArgs = view.getUint8(pCounter+2);
                pCounter+=3;
                break;
            case  15 :               /* HB_P_GREATER checks if the second latest value on the stack is greater that the latest one */
                stack.push(stack.popValue()<stack.popValue()); //I changed the direction because the value are swapped
                pCounter+=1;
                break;
            case  16 :          /* HB_P_GREATEREQUAL checks if the second latest value on the stack is greater equal that the latest one, leaves the result only */
                stack.push(stack.popValue()<=stack.popValue()); //I changed the direction because the value are swapped
                pCounter+=1;
                break;
            case  18 : {               /* HB_P_DIVIDE divides the latest two values on the stack, removing them and leaving the result */
                let v = stack.popValue();
                stack.push(stack.popValue()/v);
                pCounter+=1;
                break; }
            case  21 :             /* HB_P_DUPLICATE places a copy of the latest virtual machine stack value on to the stack */
                stack.push(stack[stack.length-1]);
                pCounter+=1;
                break;
            case  22 : {        /* HB_P_PUSHTIMESTAMP places a timestamp constant value on the virtual machine stack */
                var v = new HBDateTime(view.getUint32(pCounter+1,true),view.getUint32(pCounter+5,true));
                stack.push( v );
                pCounter+=9;
                break; }
            case  24 :              /* HB_P_INSTRING checks if the second latest value on the stack is a substring of the latest one */
                stack.push(stack.popValue().indexOf(stack.popValue())>=0);
                pCounter+=1;
                break;
            case  25 :              /* HB_P_JUMPNEAR jumps to a relative offset 1 Byte */
                pCounter+=view.getInt8(pCounter+1,true);
                break;
            case  26 :                  /* HB_P_JUMP jumps to a relative offset 2 Bytes */
                pCounter+=view.getInt16(pCounter+1,true);
                break;
            case  27 :               /* HB_P_JUMPFAR jumps to a relative offset 3 Bytes */
                pCounter+=view.getInt32(pCounter+1,true);
                break;
            case  28 :         /* HB_P_JUMPFALSENEAR checks a logic expression of the stack and jumps to a relative offset */
            case  29 :             /* HB_P_JUMPFALSE checks a logic expression of the stack and jumps to a relative offset */
            case  30 :          /* HB_P_JUMPFALSEFAR checks a logic expression of the stack and jumps to a relative offset */
            case  31 :          /* HB_P_JUMPTRUENEAR checks a logic expression of the stack and jumps to a relative offset */
            case  32 :              /* HB_P_JUMPTRUE checks a logic expression of the stack and jumps to a relative offset */
            case  33 :           /* HB_P_JUMPTRUEFAR checks a logic expression of the stack and jumps to a relative offset */
                if(pCode<31? !stack.popValue() : stack.popValue())
                    switch(pCode%3) {
                        case 1: // 28 - 31
                            pCounter+=view.getInt8(pCounter+1,true);
                            break;
                        case 2: // 29-32
                            pCounter+=view.getInt16(pCounter+1,true);
                            break;
                        case 0: // 30-33
                            pCounter+=view.getInt32(pCounter+1,true);
                            break;
                }
                else
                    pCounter+=[2,3,5,2,3,5][pCode-28];
                break;
            case  34 :             /* HB_P_LESSEQUAL checks if the second latest value on the stack is less equal that the latest one, leaves the result only */
                stack.push(stack.popValue()>=stack.popValue()); //I changed the direction because the value are swapped
                pCounter+=1;
                break;
            case  35 :                  /* HB_P_LESS checks if the second latest value on the stack is less that the latest one */
                stack.push(stack.popValue()>stack.popValue()); //I changed the direction because the value are swapped
                pCounter+=1;
                break;
            case  36 :                  /* HB_P_LINE currently compiled source code line number */
                currLine = view.getUint16(pCounter+1,true);
                pCounter+=3;
                break;
            case  48 :               /* HB_P_MESSAGE sends a message to an object */
                stack.push( this.symbols[view.getUint16(pCounter+1,true)]);
                pCounter+=3;
                break;
            case  49 :                 /* HB_P_MINUS subs the latest two values on the stack, removing them and leaving the result */
                stack.push(-stack.popValue()+stack.popValue());
                pCounter+=1;
                break;
            /* start: pcodes generated by the macro compiler - the symbol address is used */
            /* end: */
            case  65 :                  /* HB_P_MULT multiplies the latest two values on the stack, removing them and leaving the result */
                stack.push(stack.popValue()*stack.popValue());
                pCounter+=1;
                break;
            case  66 :                /* HB_P_NEGATE numerically negates the latest value on the stack */
                stack[stack.length-1]=-stack[stack.length-1]
                pCounter+=1;
                break;
            case  68 :                   /* HB_P_NOT logically negates the latest value on the stack */
                stack.push(!stack.popValue());
                pCounter+=1;
                break;
            case  69 :              /* HB_P_NOTEQUAL checks if the latest two stack values are equal, leaves just the result */
                stack.push(stack.popValue()!=stack.popValue());
                pCounter+=1;
                break;
            case  72 : {                 /* HB_P_PLUS adds the latest two values on the stack, removing them and leaving the result */
                let v1=stack.popValue();
                let v2=stack.popValue();
                if(typeof(v1)=="object" && v1.constructor==HBDateTime || v1.constructor==Date)  {
                    v1=v1.constructor==Date? new HBDateTime(v1) : v1;
                    if(typeof(v2)=="object" && v2.constructor==Date)
                        v2=new HBDateTime(v2);
                    stack.push(new Date(v1.add(v2)));
                }
                else if(typeof(v2)=="object" && v2.constructor==HBDateTime || v2.constructor==Date) {
                    v2=v2.constructor==Date? new HBDateTime(v2) : v2;
                    stack.push(new Date(v2.add(v1)));
                } else
                    stack.push(v2+v1);
                pCounter+=1;
                break; }
            case  73 :                   /* HB_P_POP removes the latest value from the stack */
                stack.popValue();
                pCounter++;
                break;
            case  80 : {         /* HB_P_POPLOCALNEAR pops the contents of the virtual machine stack onto a local variable */
                let id = view.getUint8(pCounter+1);
                if(id<=nArgs)
                    args[id-1] = stack.popValue();
                else
                    locals[id-1-nArgs] = stack.popValue();
                pCounter += 2;
                break; }
            case  82 : {            /* HB_P_POPSTATIC pops the contents of the virtual machine stack onto a static variable */
                let id = view.getUint16(pCounter+1, true);
                this.statics[id-1] = stack.popValue();
                pCounter += 3;
                break; }
            case  89 : {            /* HB_P_PUSHBLOCK start of a codeblock definition */
                let nSize = view.getUint16(pCounter+1, true);
                stack.push(this.getCB(code.slice(pCounter, pCounter+nSize)));
                pCounter+=nSize;
                break; }
            case  92 :              /* HB_P_PUSHBYTE places a 1 byte integer number on the virtual machine stack */
                stack.push( view.getInt8(pCounter+1));
                pCounter+=2;
                break;
            case  93 :               /* HB_P_PUSHINT places an integer number on the virtual machine stack */
                stack.push( view.getInt16(pCounter+1,true));
                pCounter+=3;
                break;
            case  95 : {        /* HB_P_PUSHLOCALNEAR pushes the contents of a local variable to the virtual machine stack */
                let id = view.getUint8(pCounter+1);
                if(id<=nArgs)
                    stack.push( args[id-1]);
                else
                    stack.push( locals[id-1-nArgs]);
                pCounter += 2;
                break; }
            case  97 :              /* HB_P_PUSHLONG places an integer number on the virtual machine stack */
                stack.push( view.getInt32(pCounter+1,true));
                pCounter+=5;
                break;
            case  98 :            /* HB_P_PUSHMEMVAR pushes the contents of a memvar variable to the virtual machine stack */
                stack.push(getSymbol(this.context, this.symbols[view.getUint16(pCounter+1,true)], true))
                pCounter+=3;
                break;
//            case  99 :         /* HB_P_PUSHMEMVARREF pushes the a memvar variable by reference to the virtual machine stack */
//                stack.push.
//                break;
            case 100 :               /* HB_P_PUSHNIL places a nil on the virtual machine stack */
                stack.push( undefined );
                pCounter++;
                break;
            case 101 :  {         /* HB_P_PUSHDOUBLE places a double number on the virtual machine stack */
                stack.push(view.getFloat64(pCounter+1,true));
                // let size = view.getUint8(pCounter+9);
                // let decimals = view.getUint8(pCounter+10);
                // TODO: size and decimal ignored.
                pCounter+=11;
                break; }
            case 103 :  {          /* HB_P_PUSHSTATIC pushes the contents of a static variable to the virtual machine stack */
                let id =  view.getUint16(pCounter+1,true);
                stack.push(this.statics[id-1]);
                pCounter+= 3;
                break; }
            case 104 : {        /* HB_P_PUSHSTATICREF pushes the a static variable by reference to the virtual machine stack */
                let id =  view.getUint16(pCounter+1,true);
                stack.push(new VarReference(this.statics,id-1));
                pCounter+= 3;
                break; }
            case 106 : {         /* HB_P_PUSHSTRSHORT places a string on the virtual machine stack */
                let len =  view.getUint8(pCounter+1);
                stack.push( view.toStringANSI(pCounter+2,len));
                pCounter+=2+len;
                break; }
            case 110 :              /* HB_P_RETVALUE instructs the virtual machine to return the latest stack value */
                returnVal = stack.popValue();
                pCounter+=1;
                break;
            case 111 :                  /* HB_P_SEND send operator */
            case 112 : {            /* HB_P_SENDSHORT send operator */
                    let nParam = pCode&1? view.getUint16(pCounter+1,true) : view.getUint8(pCounter+1,true);
                    let params = stack.splice(stack.length-nParam);
                    let pThis = stack.popValue();
                    let fn = getSymbol(pThis, stack.pop(), true);
                    let ret;
                    if( typeof(fn) == "string") {
                        if(params.length==1) pThis[fn] = params[0];
                        ret = pThis[fn];
                    } else if( typeof(fn) == "function")
                        ret = fn.apply(pThis,params);
                    else
                        ret = fn;
                    stack.push(ret);
                    pCounter += pCode&1? 3 : 2;
                break; }
            case 116 :                /* HB_P_SFRAME sets the statics frame for a function */
                //currently ignored
                pCounter+= 3;
                break;
            case 117 :               /* HB_P_STATICS defines the number of statics variables for a PRG */
                this.statics = new Array(view.getUint16(pCounter+3,true));
                pCounter+=5;
                break;
            case 120 :                  /* HB_P_TRUE pushes true on the virtual machine stack */
                stack.push( true );
                pCounter+=1;
                break;
            case 121 :                  /* HB_P_ZERO places a ZERO on the virtual machine stack */
                stack.push( 0 );
                pCounter+=1;
                break;
            case 122 :                   /* HB_P_ONE places a ONE on the virtual machine stack */
                stack.push( 1 );
                pCounter+=1;
                break;
            case 134 : {          /* HB_P_PUSHDATE places a data constant value on the virtual machine stack */
                var v = new HBDateTime(view.getUint32(pCounter+1,true));
                stack.push(v);
                pCounter+=5;
                break; }
            case 135 : {            /* HB_P_PLUSEQPOP adds a value to the variable reference */
                let d = stack.popValue();
                let v = stack.pop();
                var dest =v.value();
                if(typeof(dest)=="object" && dest.constructor==HBDateTime) {
                    dest.add(d);
                } else
                    v.arr[v.idx]+=d;
                pCounter++;
                break;  }
            case 136 : {           /* HB_P_MINUSEQPOP subs a value from the variable reference */
                let d = stack.popValue();
                let v = stack.pop();
                if(typeof(v)!="object" || v.constructor!=VarReference) throw "VM error";
                v.arr[v.idx]-=d;
                break;  }
            /* optimization of inlined math operations */
            case 148 : {         /* HB_P_ARRAYPUSHREF pushes reference to array element */
                let idx = stack.popValue()-1;
                let arr = stack.popValue();
                stack.push( new VarReference(arr,idx) );
                pCounter++;
                break;
            }
            case 165 : {            /* HB_P_PUSHUNREF push unreferenced top item on HVM stack */
                /** @type {Object} */
                let v = stack.popValue();
                if(typeof(v)=="object") {
                    if(Array.isArray(v))
                        v=Array.from(v);
                    else
                        v={...v};
                }
                stack.push(v);
                pCounter+=1;
                break; }
            case 169 : {             /* HB_P_DECEQPOP decrements the var reference */
                let v= stack[stack.length-1];
                if(typeof(v)=="object" && v.constructor==VarReference)
                    v.arr[v.idx]--;
                else
                    stack[stack.length-1]--;
                pCounter++;
                break; }
            case 175 : {         /* HB_P_LOCALINCPUSH increments the local variable, push result on the stack */
                let id = view.getUint16(pCounter+1,true);
                if(id<=nArgs) {
                    ++args[id-1];
                    stack.push(args[id-1]);
                } else {
                    ++locals[id-1-nArgs];
                    stack.push( locals[id-1-nArgs]);
                }
                pCounter += 3;
                break; }
            case 176 :           /* HB_P_PUSHFUNCSYM places a symbol on the virtual machine stack */
                stack.push( getSymbol(this.context, this.symbols[view.getUint16(pCounter+1,true)], true) );
                pCounter+=3;
                break;
            default:
                throw "unimplented pCode "+pCode + " in line "+currLine;
        }
    }
}

HRB.prototype.getFn = function(code) {
    var tc = this;
    return function() { return tc.runCode(code,arguments); }
}

/**
 * @param {DataView} code
 */
HRB.prototype.getCB = function(code) {
    var view = new DataView(code);
    var tc = this;
    var nArgs = view.getUint16(3,true);
    var nLocals = view.getUint16(5,true);
    return function() { return tc.runCode(code.slice(7+nLocals*2),arguments, nLocals, nArgs); }
}

HRB.prototype.getFunctionByName = function(name) {
    name=name.toUpperCase();
    for (let i = 0; i < this.functions.length; i++) {
        const thisFn = this.functions[i];
        if(thisFn.name==name)
            return thisFn;
    }
    return undefined;
}

HRB.prototype.getFirstSymb = function() {
    for (let i = 0; i < this.symbols.length; i++) {
        /** @type {HRBsymb} */
        const thisSymb = this.symbols[i];
        if(thisSymb.scope & HB_FS.FIRST )
            return thisSymb;
    }
    return undefined;
}

HRB.prototype.apply = function() {
    for(const i in this.functions) {
        if (this.functions.hasOwnProperty(i)) {
            const thisFn = this.functions[i];
            thisFn.definition = this.context[thisFn.name] = this.getFn(thisFn.code);
        }
    }
    for(const i in this.symbols) {
        if (this.symbols.hasOwnProperty(i)) {
            if( (this.symbols[i].scope & HB_FS.PUBLIC) ||
                (this.symbols[i].scope & HB_FS.STATIC) ||
                (this.symbols[i].scope & HB_FS.INIT))  {
                this.symbols[i].ptr = this.getFunctionByName(this.symbols[i].name); // ajust added
                if(!this.symbols[i].ptr) throw "unfound local symbol "+ this.symbols[i].name
                this.symbols[i].ptr=this.symbols[i].ptr.definition;
                if((this.symbols[i].scope & 8)) {
                    // execute it because is init
                    this.symbols[i].ptr();
                }
            } else if(!this.symbols[i].scope & HB_FS.MESSAGE )
                getSymbol(this.context, this.symbols[i], false);
        }

    }
}

HRB.prototype.replaceSymbol = function(symbName, fn) {
    symbName = symbName.toUpperCase();
    var symb = this.symbols.find((v) => v.name = symbName );
    if(symb) {
        symb.ptr = fn;
        return true;
    }
    return false;
}

document.addEventListener("DOMContentLoaded", (e) => {
    var scripts = document.getElementsByTagName( 'script' );
    /** @type {Array<Promise<HRB>>} */
    var promises = [];
    for (let i = 0; i < scripts.length; i++) {
        const scr = scripts[i];
        if(scr.getAttribute("type")=="harbour/hrb") {
            var hrb = new HRB();
            promises.push(hrb.download(scr.getAttribute("src")));
        }
    }
    if(promises.length>0)
        Promise.all(promises).then((hrbs)=>{
            if(hrbs.length>0) {
                var mainFn;
                for(var i=0;i<hrbs.length;i++) {
                    hrbs[i].apply();
                    mainFn = mainFn || hrbs[i].getFunctionByName("MAIN");
                }
                if(mainFn)
                    mainFn.definition();
                else {
                    mainFn = hrbs[0].getFirstSymb();
                    if(mainFn)
                        mainFn.ptr();
                }
            }
        });
})

window.HRB = HRB;