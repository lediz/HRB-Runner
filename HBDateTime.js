class HBDateTime extends Date {
    constructor(lJulian, lMilliseconds) {
        if(typeof(lJulian)=="number" && arguments.length<=2) {
            super(0);
            this.dateDecode(lJulian, lMilliseconds);
        } else {
            // can't I use call?
            switch(arguments.length) {
                case 0: super(); break;
                case 1: super(arguments[0]); break;
                case 2: super(arguments[0],arguments[1]); break;
                default:
                    throw "unimplemented";
            }
        }
    }
    dateDecode(lJulian, lMilliseconds) {
        // void hb_dateDecode( long lJulian, int * piYear, int * piMonth, int * piDay )
        var U, V, W, X, J;
        J = Math.floor(lJulian);
        if(lJulian!=J) {
            if(typeof(lMilliseconds)!="number")
                lMilliseconds=0;
            lMilliseconds+=(lJulian-J)*24*60*60*1000;
        }
        J += 68569;
        W = Math.floor((J * 4) / 146097);
        J -= Math.floor(((146097 * W) + 3) / 4);
        X = Math.floor(4000 * (J + 1) / 1461001);
        J -= Math.floor((1461 * X) / 4) - 31;
        V = Math.floor(80 * J / 2447);
        U = Math.floor(V / 11);
        var piYear = Math.floor(X + U + (W - 49) * 100);
        var piMonth = Math.floor(V + 2 - (U * 12));
        var piDay = Math.floor(J - (2447 * V / 80));
        //*/
        this.setFullYear(piYear, piMonth - 1, piDay + 1);
        this.isDateTime = typeof(lMilliseconds) == "number";
        this.setHours(0,0,0,0);
        if(this.isDateTime) {
            this.setMilliseconds(lMilliseconds);
        }
    }
    add(v) {
        if(typeof(v)=="number") {
            var J = Math.floor(v);
            this.setDate(this.getDate()+J);
            if(J!=v) {
                var M=(v-J)*24*60*60*1000;
                this.setMilliseconds(this.getMilliseconds()+M);
            }
        } else {
            //var d=this;
            //d+=v;
            //this=d;
        }
        return this;
    }
}

module.exports = HBDateTime;
