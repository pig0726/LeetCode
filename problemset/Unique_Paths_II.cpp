class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (!n) return 0;
        int m = obstacleGrid[0].size();
        if (!m) return 0;
        dp.resize(n, vector<ll>(m, 0));
        if (!obstacleGrid[n-1][m-1]) dp[n-1][m-1] = 1;
        for (int i = m-2; i >= 0; --i) 
            if (dp[n-1][i+1] && !obstacleGrid[n-1][i]) 
                dp[n-1][i] = 1;
        for (int i = n - 2; i >= 0; --i)
            for (int j = m-1; j >= 0; --j) {
                if (obstacleGrid[i][j]) continue;
                dp[i][j] += dp[i+1][j];
                if (j != m-1) dp[i][j] += dp[i][j+1];
            }
        return dp[0][0];
    }
};
