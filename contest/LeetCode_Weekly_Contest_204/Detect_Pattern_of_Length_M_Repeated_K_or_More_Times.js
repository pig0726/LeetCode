/**
 * @param {number[]} arr
 * @param {number} m
 * @param {number} k
 * @return {boolean}
 */
var containsPattern = function(arr, m, k) {
    var len = m * k;
    var n = arr.length;
    for (var i = 0; i + len <= n; ++i) {
        var flag = true;
        for (var j = i; j < i+len; j += m) {
            for (var idx = 0; idx < m; idx++)
                if (arr[i+idx] != arr[j+idx]) {
                    flag = false;
                    break;
                }
            if (!flag) break;
        }
        if (flag) return true;
    }
    return false;
};