var currPos = undefined;
function SetPos(y,x) {
    currPos = [x,y];
}

function MaxRow() {
    var fontH = parseInt(window.getComputedStyle(document.body).getPropertyValue('font-size'));
    return Math.round(window.innerHeight / fontH);

}

var currColor = undefined;
function SetColor(c) {
    currColor = c;
}

function SetCursor() {}

function ASize(arr,n) {
    arr.length=n;
    return arr;
}

function Len(arr) {
    return arr.length;
}

function PrepareQOut(checkOld) {
    /** @type{HTMLSpanElement} */
    var dest;
    while(checkOld) {
        dest = document.body.children;
        dest=dest[dest.length-1];
        if(dest.tagName!="SPAN") break;
        if(currPos) {
            dest.style.position="absolute";
            dest.style.left = currPos[0]+"em";
            dest.style.top = currPos[1]+"em";
        }
        return dest;
    }
    dest = document.createElement("span")
    document.body.appendChild(dest);
    return dest;
}

function ArgQOut() {
    var txt = "";
    for(let i=0;i<arguments.length;i++) {
        if(i>0) txt+=" ";
        txt+=arguments[i];
    }
    return txt;
}

function QOut() {
    var dest = PrepareQOut(false);
    dest.textContent = ArgQOut.apply(undefined,arguments);
}

function QQOut() {
    var dest = PrepareQOut(true);
    dest.textContent = ArgQOut.apply(undefined,arguments);
}

function myAChoice(nTop, nLeft, nBottom, nRight, acItems, xSelect, xUserFunc, nPos, nHiLiteRow) {
    var mainEle = document.createElement("select");
    mainEle.size = nBottom-nTop;
    mainEle.style.position="absolute";
    mainEle.style.left = nLeft+"em";
    mainEle.style.top = nTop+"em";
    mainEle.style.width = (nRight-nLeft)+"em";
    nPos = (typeof(nPos)!="number"? 1 : nPos)-1;
    for (let i = 0; i < acItems.length; i++) {
        var opt = document.createElement("option")
        opt.textContent = acItems[i];
        if(typeof(nPos)!="number") {
            if(i==nPos) opt.selected=true;
        } else {
            opt.selected=true;
            nPos=i;
        }
        if(Array.isArray(xSelect) && i<=xSelect.length && !xSelect[i-1])
            opt.disabled=true;
        mainEle.add(opt);
    }
    if(xUserFunc) {
        if(typeof(xUserFunc)=="string") {
            xUserFunc = getSymbol(window,{"name":xUserFunc.toUpperCase()});
        }
        if(xUserFunc) {
            mainEle.addEventListener("change", function(evt) {
                xUserFunc(0,mainEle.selectedIndex+1);
            })
        }
    }
    document.body.appendChild(mainEle);
    mainEle.focus();
}

var hrb = new HRB();
hrb.download("achoice.hrb").then((v)=>{
    console.log(v);
    hrb.apply();
    // the HBR contains a function with the same name of program,
    // in this case is empty and overwrite the aChoice method
    hrb.replaceSymbol("ACHOICE",myAChoice)
    MAIN();
});
