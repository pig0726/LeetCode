const int N = 105;
class Solution {
public:
    int p[N];
    int n;
    
    int find(int x) { 
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    int mst(vector<vector<int>>& edges, int idx) {
        for (int i = 0; i < n; ++i) p[i] = i;
        
        int cost = 0;
        for (int i = 0; i < edges.size(); ++i) if (i != idx) {
            int pa = find(edges[i][1]);
            int pb = find(edges[i][2]);
            // printf("find a:%d, b:%d, pa:%d, pb:%d\n", edges[i][0], edges[i][1], pa, pb);
            if (pa != pb) {
                p[pb] = pa;
                cost += edges[i][0];
                //printf("get [%d %d]: %d, %d\n", edges[i][0], edges[i][1], edges[i][2], edges[i][3]);
            }
        }
        return cost;
    }
    
    int mst2(vector<vector<int>>& edges, int idx) {
        for (int i = 0; i < n; ++i) p[i] = i;
        
        int cost = edges[idx][0];
        int pa = find(edges[idx][1]);
        int pb = find(edges[idx][2]);
        p[pb] = pa;
        
        for (int i = 0; i < edges.size(); ++i) {
            int pa = find(edges[i][1]);
            int pb = find(edges[i][2]);
            if (pa != pb) {
                p[pb] = pa;
                cost += edges[i][0];
            }
        }
        
        return cost;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (int i = 0; i < edges.size(); ++i) {
            std::swap(edges[i][0], edges[i][2]);
            edges[i].push_back(i);
        }
        
        sort(edges.begin(), edges.end());
        
        int cost = mst(edges, -1);
        printf("mst cost: %d\n", cost);
        
        vector<int> reta, retb;
        
        for (int i = 0; i < edges.size(); ++i) {
            int tmp = mst(edges, i);
            if (tmp != cost) {
                reta.push_back(edges[i][3]);
            } else {
                int tmp2 = mst2(edges, i);
                if (tmp2 == cost) {
                    retb.push_back(edges[i][3]);
                }
            }
        }
        
        vector<vector<int>> ret{reta, retb};
        return ret;
    }
};
