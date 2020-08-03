class Solution {
public:
    struct Elem {
        int id;
        char c;
        vector<int> cnt;
        
        Elem(int i, char ch): id(i), c(ch) {
            cnt.assign(26, 0);
        }
    };
    vector<vector<int>> e;
    vector<Elem> data;
    vector<bool> vis;
    
    void dfs(int u) {
        vis[u] = true;
        for (int v : e[u]) {
            if (vis[v]) continue;
            dfs(v);
            for (int i = 0; i < 26; ++i)
                data[u].cnt[i] += data[v].cnt[i];
                data[u].cnt[data[v].c - 'a'] += 1;
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        e.assign(n, vector<int>());
        vis.assign(n, false);
        data.clear();
        for (const auto& p : edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < n; ++i)
            data.push_back(Elem(i, labels[i]));
        
        dfs(0);
        
        vector<int> ret;
        for (int i = 0; i < n; ++i)
            ret.push_back(data[i].cnt[data[i].c - 'a']+1);
        return ret;
    }
};
