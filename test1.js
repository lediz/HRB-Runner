function QOUT(a) {
    var dest = document.createElement("span")
    dest.textContent = a;
    document.body.appendChild(dest);
}

var hrb = new HRB();
hrb.download("test1.hrb").then((v)=>{
    console.log(v);
    hrb.apply();
    MAIN();
});
