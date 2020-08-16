/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function(arr) {
    var n = arr.length;
    for (var i = 0; i+3 <= n; i++) {
        var flag = true;
        for (var k = 0; k < 3; k++) {
            if (arr[i+k] % 2 != 1) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
};
