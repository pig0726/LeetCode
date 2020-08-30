/**
 * @param {number[]} nums
 * @return {number}
 */
var getMaxLen = function(nums) {
    var n = nums.length;
    var L = 0, R = 0, ret = 0;
    while (L < n) {
        while (R < n && nums[R] === 0) R++;
        L = R;
        var neg = 0;
        while (R < n && nums[R] !== 0) {
            if (nums[R] < 0) neg++;
            if (!(neg & 1)) ret = Math.max(ret, R - L + 1); 
            R++;
        }
        while (L < R) {
            if (!(neg & 1)) ret = Math.max(ret, R - L);
            if (nums[L] < 0) neg--;
            L++;
        }
    }
    return ret;
};