class Solution {
public:
    vector<int> pos[10];
    int n;
    bool isTransformable(string s, string t) {
        n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - '0';
            pos[idx].push_back(i);
        }
        
        vector<int> p(10, 0);
        
        for (int i = 0; i < t.length(); ++i) {
            int idx = t[i] - '0';
            if (p[idx] >= pos[idx].size()) return false;
            
            int where = pos[idx][p[idx]];
            p[idx]++;
            
            for (int v = 0; v < idx; ++v) {
                if (p[v] >= pos[v].size()) continue;
                if (pos[v][p[v]] < where) return false;
            }
        }
        
        return true;
    }
};
