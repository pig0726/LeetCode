/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
var minCost = function(n, cuts) {
    cuts.sort(function(a, b) { return a - b; });
    var m = cuts.length;
    var dp = [];
    for (var i = 0; i <= m; ++i) {
        dp[i] = [];
        for (var j = 0; j <= m; ++j)
            dp[i][j] = -1;
    }
    
    var dfs = function(st, ed) {
        if (ed < st) return 0;
        if (dp[st][ed] != -1) return dp[st][ed];
        
        var L = 0, R = n;
        if (st != 0) L = cuts[st-1];
        if (ed != m-1) R = cuts[ed+1];
        
        var ret = Number.MAX_SAFE_INTEGER;
        dp[st][ed] = ret;
        var val = R - L;
        for (var i = st; i <= ed; i++) if (L < cuts[i] && cuts[i] < R) {
            ret = Math.min(ret, dfs(st, i-1) + dfs(i+1, ed) + val);
        }
        if (ret === Number.MAX_SAFE_INTEGER) 
            ret = 0;
        dp[st][ed] = ret;
        return ret;
    };
    
    return dfs(0, m-1);
};
