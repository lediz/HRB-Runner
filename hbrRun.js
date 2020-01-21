function HRB() {
    this.functions=[];
    this.symbols=[];
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
 *
 * @param {ArrayBuffer} binHRB
 * @param {function(Object)} onDone
 * @param {function(String)} onError
 */
HRB.prototype.loadFromBuffer = function(binHRB, onDone, onError) {
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

function getSymbol(context, symb) {
    if(symb.name in context && typeof(context[symb.name]) == "function" )
        return context[symb.name];
    if(context!=window) return getSymbol(window,symb);
    return undefined;
}

//from harbour\include\hbpcode.h
//HRB.pCodes

HRB.prototype.runCode = function(context,code,args) {
    var view = new DataView(code);
    var pCounter = 0;
    var stack = [];
    while(true) {
        var pCode = view.getUint8(pCounter);
        switch(pCode) {
            case 7: return; //HB_P_ENDPROC
            case 20: //HB_P_DOSHORT
                var nParam = view.getUint8(pCounter+1,true);
                var params = [];
                for(i=0;i<nParam;i++) {
                    params.push(stack.pop().value);
                }
                stack.pop().value.apply(undefined,params);
                pCounter += 2;
                break;
            case 36: //HB_P_LINE
                //var currLine = view.getUint16(pCounter+1,true);
                pCounter+=3;
                break;
            case 106:  //HB_P_PUSHSTRSHORT
                var len =  view.getUint8(pCounter+1,true);
                stack.push( {type:"char", value: view.toStringANSI(pCounter+2,len) });
                pCounter+=2+len;
                break;
            case 176: //HB_P_PUSHFUNCSYM
                stack.push( {type:"symb", value: getSymbol(context, this.symbols[view.getUint16(pCounter+1,true)]) });
                pCounter+=3;
                break;
            default:
                throw "unimplented pCode "+pCode;
        }
    }
    for (let pPoint = 0; pPoint < view.length; pPoint++) {
        const pCode = view[pPoint];

    }
}

HRB.prototype.getFn = function(context,code) {
    return () => this.runCode(context,code,arguments);
}

HRB.prototype.apply = function(context) {
    if(!context) context=window;
    for (const i in this.functions) {
        if (this.functions.hasOwnProperty(i)) {
            const thisFn = this.functions[i];
            context[thisFn.name] = this.getFn(context,thisFn.code);
        }
    }
}
