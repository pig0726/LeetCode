class Solution {
public:
    inline static const int INF = 0x3f3f3f3f;
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        if (!m) return 0;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        dp[n-1][m-1] = grid[n-1][m-1];
        for (int i = m-2; i >= 0; --i) 
            dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];
        for (int i = n-2; i >= 0; --i) 
            for (int j = m-1; j >= 0; --j) {
                int min_val = dp[i+1][j];
                if (j != m-1 && dp[i][j+1] < min_val) min_val = dp[i][j+1];
                dp[i][j] = grid[i][j] + min_val;
            }
        return dp[0][0];
    }
};
