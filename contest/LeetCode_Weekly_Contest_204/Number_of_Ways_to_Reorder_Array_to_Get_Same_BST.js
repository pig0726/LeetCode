const MOD = BigInt(1000000007);
const N = 1005;

var f = null;

function dfs(nums) {
    if (nums.length <= 1) return BigInt(1);
    var a = [], b = [];
    var root = nums[0];
    var n = nums.length;
    for (var i = 1; i < n; ++i) {
        if (nums[i] < root) a.push(nums[i]);
        else b.push(nums[i]);
    }
        
    var acnt = a.length;
    var bcnt = b.length;
        
    var sum = f[acnt][bcnt];
    sum = BigInt(BigInt(sum) * BigInt(dfs(a))) % MOD;
    sum = BigInt(BigInt(sum) * BigInt(dfs(b))) % MOD;
        
    return BigInt(sum);
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var numOfWays = function(nums) {
    var n = nums.length;
        
    f = new Array()
    for (var i = 0; i <= n; ++i) {
        f[i] = new Array()
        for (var j = 0; j <= n; ++j)
            f[i][j] = BigInt(0)
    }
        
    for (var i = 1; i <= n; ++i)
        f[i][0] = f[0][i] = BigInt(1);
        
    for (var i = 1; i <= n; ++i)
        for (var j = 1; j <= n; ++j) {
            f[i][j] = BigInt(f[i][j-1] + f[i-1][j]) % MOD;
        }
        
    var ret = dfs(nums);
    return (ret - BigInt(1) + MOD) % MOD;
};