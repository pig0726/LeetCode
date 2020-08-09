/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
var findKthBit = function(n, k) {
    k--;
    n--;
    var ret = [0];
    for (var i  = 0; i < n; ++i) {
        var b = [];
        for (var j = ret.length-1, id = 0; j >= 0; --j, id++) {
            b[id] = 1 - ret[j];
        }
        ret = ret.concat([1], b);
    }
    
    return ret[k].toString();
};
