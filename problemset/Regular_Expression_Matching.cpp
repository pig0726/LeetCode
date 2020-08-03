#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n = 0;
    int m = 0;
    vector<vector<bool>> dp;
    vector<vector<bool>> vis;

    bool dfs(const std::string& s, const std::string& p, int idxs, int idxp) {
      if (idxs >= n && idxp >= m) return true;
      if (idxp >= m) return false;
      if (vis[idxs][idxp]) return dp[idxs][idxp];
      vis[idxs][idxp] = true;

      assert(p[idxp] != '*');

      if (idxs == n) {
        if (idxp + 1 < m && p[idxp + 1] == '*')
          dp[idxs][idxp] = dfs(s, p, idxs, idxp + 2);
        return dp[idxs][idxp];
      }

      if (p[idxp] == '.') {
        if (idxp + 1 == m || p[idxp+1] != '*') {
          dp[idxs][idxp] = dfs(s, p, idxs+1, idxp+1);
        } else {
          for (int i = 0; !dp[idxs][idxp] && i + idxs <= n; ++i) {
            dp[idxs][idxp] = dfs(s, p, idxs+i, idxp+2);
          }
        }
      } else {
        if (idxp + 1 == m || p[idxp+1] != '*') {
          if (s[idxs] != p[idxp]) return false;
          else dp[idxs][idxp] = dfs(s, p, idxs+1, idxp+1);
        } else {
          dp[idxs][idxp] = dfs(s, p, idxs, idxp+2);
          if (dp[idxs][idxp]) return true;

          for (int i = 0; !dp[idxs][idxp] && i + idxs < n; ++i) {
            if (s[idxs+i] != p[idxp]) break;
            dp[idxs][idxp] = dfs(s, p, idxs+i+1, idxp+2);
          }
        }
      }

      return dp[idxs][idxp];
    }

    bool isMatch(string s, string p) {
      n = s.length();
      m = p.length();
      dp.resize(n+1, vector<bool>(m+1, false));
      vis.resize(n+1, vector<bool>(m+1, false));

      bool ret = dfs(s, p, 0, 0);
      return ret;
    }
};
