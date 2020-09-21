class Solution {
public:
    unordered_map<int, int> m[1000];
    bool work(int x, int y, int u, int v) {
        int pu = m[x][u];
        int py = m[x][y];
            
        int px = m[u][x];
        int pv = m[u][v];
        
        if (pu < py && px < pv) return true;
        return false;
    }
    int unhappyFriends(int n, vector<vector<int>>& ps, vector<vector<int>>& pairs) {
        vector<bool> vis(n, true);
        
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < ps[i].size(); ++k)
                m[i][ps[i][k]] = k;
        }
        for (int i = 0; i < pairs.size(); ++i) {
            for (int j = 0; j < pairs.size(); ++j) if (i != j) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                
                if (work(x, y, u, v)) vis[x] = false;
                if (work(y, x, u, v)) vis[y] = false;
                if (work(x, y, v, u)) vis[x] = false;
                if (work(y, x, v, u)) vis[y] = false;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
            if (!vis[i]) ++ret;
        return ret;
    }
};
