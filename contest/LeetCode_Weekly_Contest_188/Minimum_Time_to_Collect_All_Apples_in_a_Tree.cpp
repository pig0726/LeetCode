class Solution {
public:
    vector<int> cnt;
    int n;
    vector<vector<int>> edges;
    vector<bool> hasApple, vis;
    int result;

    void dfs0(int u) {
        vis[u] = true;
        if (hasApple[u]) cnt[u]++;

        for (int v : edges[u]) if (!vis[v]) {
            dfs0(v);
            cnt[u] += cnt[v];
        }
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : edges[u]) if (cnt[v] && !vis[v]) {
            result++;
            dfs1(v);
        }

        ++result;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        cnt.assign(n, 0);
        this->edges.assign(n, vector<int>());

        for (const auto& p : edges) {
            this->edges[p[0]].push_back(p[1]);
            this->edges[p[1]].push_back(p[0]);
        }
        this->hasApple = hasApple;
        this->n = n;

        vis.assign(n, false);
        dfs0(0);

        vis.assign(n, false);
        result = 0;
        dfs1(0);
        result--;

        return result;
    }
};