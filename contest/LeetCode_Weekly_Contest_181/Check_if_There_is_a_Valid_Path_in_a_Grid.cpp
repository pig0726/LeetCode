class Solution {
public:
    struct Dir {
      int row, col;
      Dir(int r, int c): row(r), col(c) {}
    };

    inline static const 
    vector< vector<Dir> > move{
      {Dir(0, -1), Dir(0, 1)},
      {Dir(-1, 0), Dir(1, 0)},
      {Dir(0, -1), Dir(1, 0)},
      {Dir(0, 1),  Dir(1, 0)},
      {Dir(-1, 0), Dir(0, -1)},
      {Dir(-1, 0), Dir(0, 1)}
    };

    vector< vector<bool> > vis;
    vector< vector<int> > g;
    int row = -1, col = -1;

    bool check(int R, int C, int newR, int newC) {
      if (newR < 0 || newR >= row ||
          newC < 0 || newC >= col || 
          vis[newR][newC]) return false;

      int idx = g[newR][newC] - 1;
      const auto& dir = move[idx];
      for (const Dir& d : dir) {
        int tmpR = newR + d.row;
        int tmpC = newC + d.col;
        if (tmpR == R && tmpC == C) return true;
      }
      return false;
    }

    void dfs(int R, int C) {
      if (vis[R][C]) return;
      vis[R][C] = true;

      const auto& dir = move[g[R][C]-1];
      for (const Dir& d : dir) {
        int newR = R + d.row;
        int newC = C + d.col;
        if (!check(R, C, newR, newC)) continue;
        dfs(newR, newC);
      }
    }

    bool hasValidPath(vector<vector<int>>& grid) {
      row = grid.size();
      if (!row) return false;
      col = grid.front().size();
      if (!col) return false;
      g = grid;
      
      vis.assign(row, vector<bool>(col, false));
      dfs(0, 0);
      return vis[row-1][col-1];
    }
};
