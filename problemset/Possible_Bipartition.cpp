class Solution {
public:
    vector<vector<int>> edge;
    vector<int> vis;

    bool dfs(int u, int col) {
      vis[u] = col;
      for (const auto& v : edge[u]) {
        if (vis[v] == -1 && !dfs(v, 1-col)) return false;
        else if (vis[v] == col) return false;
      }
      return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      edge.resize(N+1);
      for (const auto& e : dislikes) edge[e[0]].push_back(e[1]), edge[e[1]].push_back(e[0]);
      vis.assign(N+1, -1);
      for (int i = 1; i <= N; i++) {
        if (vis[i] != -1) continue;
        if (!dfs(i, 0)) return false;
      }
      return true;
    }
};
