const int INF = 1e9;
int dp[505][505];

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        for (int i = 0; i < 505; ++i)
            for (int j = 0; j < 505; ++j)
                dp[i][j] = -INF;
        
        dp[n-1][m-1] = a[n-1] * b[m-1];
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (i == n-1 && j == m-1) continue;
                int& ret = dp[i][j];
                
                ret = max(ret, dp[i][j+1]);
                ret = max(ret, dp[i+1][j]);
                ret = max(ret, a[i] * b[j]);
                ret = max(ret, a[i] * b[j] + dp[i+1][j+1]);
                
                //printf("dp[%d][%d] = %d\n", i, j , ret);
            }
        }
        return dp[0][0];
    }
};
