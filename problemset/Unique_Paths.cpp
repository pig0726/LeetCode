class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(n, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) dp[n-1][i] = 1;
        for (int i = n-2; i >= 0; --i)
            for (int j = m-1; j >= 0; --j) {
                dp[i][j] = dp[i+1][j];
                if (j != m-1) dp[i][j] += dp[i][j+1];
            }
        return dp[0][0];
    }
};
