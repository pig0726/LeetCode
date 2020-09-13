int p[1005];
int e[1000005][3];
int idx[1000005];

class Solution {
public:
    int n = 0;
     
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
                e[k][0] = i, e[k][1] = j, e[k][2] = dist;
                idx[k] = k;
                k++;
            }
        sort(idx, idx+k, [](int i, int j) { return e[i][2] < e[j][2]; });
        
        for (int i = 0; i < n; ++i) p[i] = i;
        
        int ret = 0;
        for (int i = 0; i < k; ++i) {
            int ith = idx[i];
            int u = e[ith][0],  v = e[ith][1], w = e[ith][2];
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) continue;
            p[pu] = pv;
            ret += w;
        }
        return ret;
    }
};

