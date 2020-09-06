const int N = 100005;
const int M = 28;
int dp[N][M];

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = cost.size();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 26; ++j)
                dp[i][j] = INT_MAX;
        dp[0][26] = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (dp[i-1][26] != INT_MAX)
                dp[i][26] = dp[i-1][26] + cost[i-1];
            
            for (int c = 0; c < 26; c++) {
                if (dp[i-1][c] != INT_MAX)
                    dp[i][c] = min(dp[i][c], dp[i-1][c] + cost[i-1]);
                if (c + 'a' == s[i-1]) {
                    for (int cc = 0; cc <= 26; cc++) if (c != cc && dp[i-1][cc] != INT_MAX) {
                        dp[i][c] = min(dp[i][c], dp[i-1][cc]);
                    }   
                }
            }
        }
        
        int ret = INT_MAX;
        for (int i = 0; i <= 26; ++i)
            ret = min(ret, dp[n][i]);
        return ret;
    }
};