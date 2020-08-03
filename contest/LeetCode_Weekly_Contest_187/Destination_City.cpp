class Solution {
public:    
    string destCity(vector<vector<string>>& paths) {
        map<string, int> g;
        int tot = 0;
        vector<int> cnt;
        
        for (const auto& p : paths) {
            const auto& a = p[0];
            const auto& b = p[1];
            auto ita = g.find(a);
            auto itb = g.find(b);
            
            int idxa = -1, idxb = -1;
            
            if (ita == g.end()) {
                idxa = tot++;
                g[a] = idxa;
                cnt.push_back(0);
            } else idxa = ita->second;
            if (itb == g.end()) {
                idxb = tot++;
                g[b] = idxb;
                cnt.push_back(0);
            } else idxb = itb->second;
            
            cnt[idxa]++;
        }
        
        int idx = -1;
        for (int i = 0; i < tot; ++i) if (!cnt[i]) {
            idx = i;
            break;
        }
        
        string ret;
        for (const auto& p : g) if (p.second == idx) {
            ret = p.first;
            break;
        }
        
        return ret;
    }
};
