class Solution {
public:
    struct Edge {
        int v;
        double w;
    };
    
    double maxProbability(int n, 
                          vector<vector<int>>& edges, 
                          vector<double>& succProb, 
                          int start, 
                          int end) {
        vector<vector<Edge>> e(n, vector<Edge>());
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            Edge item{v, w};
            e[u].push_back(item);
            item.v = u;
            e[v].push_back(item);
        }
        
        using pdi = pair<double, int>;
        vector<double> d(n, 0.0);
        d[start] = 1.0;
        
        vector<bool> done(n, false);
        
        priority_queue<pdi> pq;
        pq.push(make_pair(d[start], start));
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int u = p.second;
            if (done[u]) continue;
            done[u] = true;
            
            for (int i = 0; i < e[u].size(); ++i) {
                int v = e[u][i].v;
                double w = e[u][i].w;
                double val = d[u] * w;
                if (val > d[v]) {
                    d[v] = val;
                    pq.push(make_pair(d[v], v));
                }
            }
        }
        
        return d[end];
    }
};
