class Solution {
public:
    struct Edge {
        int u, v, w;
    };
    
    int n = 0;
    Edge e[1000005];
    vector<int> p;
    
    int find(int u) {
        return u == p[u] ? u : p[u] = find(p[u]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        
        int k = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1];
                int dist = abs(xi - xj) + abs(yi - yj);
                e[k++] = Edge{i, j, dist};
            }
        
        sort(e, e + k, [](const Edge& a, const Edge& b) { 
            return a.w < b.w; 
        });
        
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        
        int ret = 0;
        for (int i = 0; i < k; ++i) {
            int u = e[i].u,  v = e[i].v, w = e[i].w;
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) continue;
            p[pu] = pv;
            ret += w;
        }
        return ret;
    }
};

