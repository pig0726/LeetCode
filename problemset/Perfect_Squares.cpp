class Solution {
public:
    int dp[1000010];
    int numSquares(int n) {
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (dp[i] == -1) dp[i] = dp[i - j * j] + 1;
                else dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
