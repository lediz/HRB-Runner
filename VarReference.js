function VarReference(arr,idx) {
    this.arr = arr;
    this.idx = idx;
}

VarReference.prototype.value = function() { return this.arr[this.idx]; }

module.exports = VarReference;