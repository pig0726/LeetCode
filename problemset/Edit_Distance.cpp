const int INF = 0x3f3f3f3f;
class Solution {
public:
    void update(int& a, const int b) { if (b < a) a = b; }
    int minDistance(string w1, string w2) {
      int n = w1.size();
      int m = w2.size();
      if (!n) return m;
      if (!m) return n;
      vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
      for (int i = 0; i <= m; ++i) dp[0][i] = i;
      for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
        for (int j = 1; j <= m; ++j) {
          int idx1 = i-1, idx2 = j-1;
          if (w1[idx1] == w2[idx2]) {
            update(dp[i][j], dp[i-1][j-1]);
          } else {
            update(dp[i][j], dp[i-1][j] + 1);
            update(dp[i][j], dp[i][j-1] + 1);
            update(dp[i][j], dp[i-1][j-1] + 1);
          }
        }
      }
      return dp[n][m];
    }
};
