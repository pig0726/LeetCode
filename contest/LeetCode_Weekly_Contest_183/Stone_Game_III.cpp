const int N = 50000 + 5;
const int INF = 1e9;
int dp[2][N];
bool vis[2][N];

class Solution {
public:
  vector<int> SV;
  vector<int> presum;
  int n;

  int cal(int l, int r) {
    if (l > r) return 0;
    return presum[r+1] - presum[l];
  }

  int dfs(int who, int idx) {
    if (idx >= n) return 0;
    if (vis[who][idx]) return dp[who][idx];
    vis[who][idx] = true;

    int& ret = dp[who][idx];
    ret = -INF;

    for (int i = 0; i < 3 && idx+i < n; ++i) {
      int get = cal(idx, idx+i);
      int ops = dfs(1-who, idx+i+1);
      int tot = cal(idx+i+1, n-1);
      int re = tot - ops;

      int value = get + re;
      if (value > ret) ret = value;
    }

    return ret;
  }

  string stoneGameIII(vector<int>& sV) {
    SV = sV;
    n = SV.size();

    memset(vis, 0, sizeof(vis));

    presum.assign(n+1, 0);
    for (int i = 1; i <= n; ++i)
      presum[i] = presum[i-1] + SV[i-1];

    dfs(0, 0);

    int& ret = dp[0][0];
    int re = presum[n] - ret;

    if (ret == re) return "Tie";
    else if (ret > re) return "Alice";
    else return "Bob";
  }
};
