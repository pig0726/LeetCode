class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int k = 1; k <= i; k++) {
                int v = dp[k-1] * dp[i - k];
                dp[i] += v;
            }
        }
        return dp[n];
    }
};
