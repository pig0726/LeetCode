class Solution {
public:
    vector<vector<bool>> dp;
    bool isMatch(string s, string p) {
      int n = s.length();
      int m = p.length();
      
      dp.resize(n+1, vector<bool>(m+1, false));
      dp[0][0] = true;

      for (int i = 1; i <= m; ++i) {
        char pc = p[i-1];
        if (pc == '*') dp[0][i] = dp[0][i-1] & true;

        for (int j = 1; j <= n; ++j) {
          if ('a' <= pc && pc <= 'z') {
            if (pc != s[j-1]) dp[j][i] = false;
            else dp[j][i] = dp[j-1][i-1];
          } else if ('?' == pc) {
            dp[j][i] = dp[j-1][i-1];
          } else {
            dp[j][i] = dp[j-1][i] | dp[j][i-1];
          }
        }
      }
      return dp[n][m];
    }
};

