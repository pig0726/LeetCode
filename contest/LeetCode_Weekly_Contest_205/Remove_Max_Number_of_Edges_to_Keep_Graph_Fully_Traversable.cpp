class Solution {
public:
    int find(int x, vector<int>& fa) { 
        return x == fa[x] ? x : fa[x] = find(fa[x], fa); 
    }
    
    void work(int& ret, int& size, vector<int>& fa, vector<pair<int, int>>& es) {
        for (const auto& e : es) {
            int u = e.first, v = e.second;
            int rootu = find(u, fa);
            int rootv = find(v, fa);
            if (rootu == rootv) {
                ret++;
                continue;
            }
            fa[rootu] = rootv;
            size++;
        }
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> p(n+1, 0);
        for (int i = 1; i <= n; ++i)
            p[i] = i;
        
        int ret = 0;
        vector<pair<int, int>> es[4];
        for (const auto& e : edges) {
            int t = e[0], u = e[1], v = e[2];
            es[t].push_back(make_pair(u, v));
        }
        
        int size = 0;
        work(ret, size, p, es[3]);
        if (size == n-1) return edges.size() - (n-1);
        
        vector<int> p1 = p;
        int size1 = size;
        work(ret, size1, p1, es[1]);
        if (size1 != n-1) return -1;
        
        vector<int> p2 = p;
        int size2 = size;
        work(ret, size2, p2, es[2]);
        if (size2 != n-1) return -1;
        
        return ret;
    }
};