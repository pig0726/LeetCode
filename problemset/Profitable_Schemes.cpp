class Solution {
public:
    int dp[2][110][110];
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
      int mod = 1e9 + 7;
      memset(dp, 0, sizeof dp);
      int now = 1, pre = 0, n = group.size();
      dp[0][0][0] = 1;
      for (int id = 0; id < n; id++) {
        for (int i = 0; i <= G; i++) {
          for (int j = 0; j <= P; j++) {
            dp[now][i][j] = dp[pre][i][j];
          }
        }

        for (int i = 0; i + group[id] <= G; i++) {
          for (int j = 0; j <= P; j++) {
            int ng = i + group[id];
            int np = j + profit[id];
            if (np > P) np = P;
            dp[now][ng][np] += dp[pre][i][j];
            dp[now][ng][np] %= mod;
          }
        }
        swap(now, pre);
      }

      int ret = 0;
      for (int i = 0; i <= G; i++) {
        ret = (ret + dp[pre][i][P]) % mod;
      }
      return ret;
    }
};
