/**
 * @param {number} n
 * @return {number}
 */
var minDays = function(n) {
    var dp = {};
    
    var dfs = function(n) {
        if (n === 0) return 0;
        else if (n === 1) return 1;
        else if (n === 2) return 2;
        
        if (dp.hasOwnProperty(n)) return dp[n];
        
        var ret = Math.min(dfs(Math.floor(n/3)) + n % 3, dfs(Math.floor(n/2)) + n % 2) + 1;
        
        dp[n] = ret;
        //console.log(n, ret);
        return ret;
    };
    
    return dfs(n);
};
