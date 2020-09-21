/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var maxNonOverlapping = function(nums, target) {
    var n = nums.length;
    var dp = [];
    for (var i = 0; i <= n; ++i) dp[i] = 0;
    var pos = {0: n};
    var suffix = 0;
    var ret = 0;
    
    for (var i = n-1; i >= 0; --i) {
        dp[i] = Math.max(dp[i], dp[i+1]);
        suffix += nums[i];
        var v = suffix - target;
        if (pos.hasOwnProperty(v)) {
            var p = pos[v];
            dp[i] = Math.max(dp[i], dp[p] + 1);
        }
        pos[suffix] = i;
        ret = Math.max(ret, dp[i]);
    }
    return ret;
};
