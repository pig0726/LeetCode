class Solution {
public:
    vector<string> g;
    vector<vector<string>> ret;
    vector<bool> visrow;
    vector<bool> k[2];
  
    void dfs(const int cur, const int n) {
      if (cur == n) {ret.push_back(g); return;}
      
      for (int r = 0; r < n; ++r) if (!visrow[r]) {
        int k0 = r - cur + n;
        int k1 = r - (n - cur) + n;
        if (k[0][k0] || k[1][k1]) continue;
        g[r][cur] = 'Q';
        k[0][k0] = k[1][k1] = visrow[r] = true;
        dfs(cur+1, n);
        g[r][cur] = '.';
        k[0][k0] = k[1][k1] = visrow[r] = false;
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      g.resize(n, std::string(n, '.'));
      visrow.resize(n, false);
      k[0].resize(2*n+1, false);
      k[1].resize(2*n+1, false);
      dfs(0, n);
      return ret;
    }
};
