class HBDateTime extends Date {
    constructor(lJulian, lMilliseconds) {
        super();
        this.lJulian = lJulian;
        this.isDateTime = typeof(lMilliseconds) == "number";
        this.lMilliseconds = this.isDateTime? lMilliseconds : 0;

        this.update()
    }
    update() {
        var lJulian = this.lJulian;
        // void hb_dateDecode( long lJulian, int * piYear, int * piMonth, int * piDay )
        var U, V, W, X, J;
        J = lJulian + 68569;
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
        if(this.isDateTime) {
            this.setHours(0,0,0,0);
            this.setMilliseconds(this.lMilliseconds);
        }
    }
    add(v) {
        if(typeof(v)=="number") {
            this.lJulian+=v;
            this.update();
        }
    }
}

module.exports = HBDateTime;
