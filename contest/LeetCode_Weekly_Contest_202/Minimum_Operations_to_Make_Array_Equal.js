/**
 * @param {number} n
 * @return {number}
 */
var minOperations = function(n) {
    var mid = n;
    var ret = 0;
    for (var i = 0; i < (n+1)>>1; ++i) {
        ret += mid - 2*i - 1;
    }
    return ret;
};
