class Solution {
public:
    unordered_map<int, int> dp;
    int dfs(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        
        if (dp.count(n)) return dp[n];
        
        int ret = min(dfs(n/3) + n % 3,  dfs(n/2) + n % 2) + 1;
        dp[n] = ret;
        
        return ret;
    }
    
    int minDays(int n) {
        dp.clear();
        return dfs(n);
    }
};
