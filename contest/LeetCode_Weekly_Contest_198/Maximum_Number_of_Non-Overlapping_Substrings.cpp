class Solution {
public:
    struct Seg {int b, e;};
    vector<Seg> seg;
    
    vector<string> maxNumOfSubstrings(string s) {
        seg.clear();
        vector<int> pos[2];
        int n = s.length();
        pos[0].assign(26, INT_MAX);
        pos[1].assign(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int& p0 = pos[0][s[i] - 'a'];
            p0 = min(p0, i);
            
            int& p1 = pos[1][s[i] - 'a'];
            p1 = max(p1, i);
        }
        
        
        for (int i = 0; i < 26; ++i) if (pos[1][i] != -1) {
            vector<bool> mark(26, false);
            mark[i] = true;
            int B = pos[0][i], E = pos[1][i];
            
            while (true) {
                bool found = false;
                int st = B, ed = E;
                for (int k = st; k <= ed; ++k) 
                    if (!mark[s[k]-'a'] && pos[1][s[k]-'a'] != -1) {
                        int idx = s[k] - 'a';
                        mark[idx] = true;
                        B = min(B, pos[0][idx]);
                        E = max(E, pos[1][idx]);
                        found = true;
                    }
                if (!found) break;
            }
            Seg e{B, E};
            seg.push_back(e);
        }
        
        sort(seg.begin(), seg.end(), 
             [](const Seg& x, const Seg& y) { 
                 return x.b < y.b; 
             });
        
        int m = seg.size();
        
        vector<int> maxcnt(m, 0);
        vector<int> minlength(m, INT_MAX);
        vector<int> step(m, -1);
        
        int tmaxcnt = 0;
        int tminlength = INT_MAX;
        int target = -1;
        
        for (int i = m-1; i >= 0; --i) {
            maxcnt[i] = 1;
            minlength[i] = seg[i].e - seg[i].b + 1;
            
            for (int j = i+1; j < m; ++j) {
                if (seg[j].b <= seg[i].e) continue;
                
                int cnt = 1 + maxcnt[j];
                int len = seg[i].e - seg[i].b + 1 + minlength[j];
                
                if (cnt > maxcnt[i] || (cnt == maxcnt[i] && len < minlength[i])) {
                    maxcnt[i] = cnt;
                    minlength[i] = len;
                    step[i] = j;
                }
            }
            
            if (maxcnt[i] > tmaxcnt || (maxcnt[i] == tmaxcnt && minlength[i] < tminlength)) {
                tmaxcnt = maxcnt[i];
                tminlength = minlength[i];
                target = i;
            }
        }
        
        vector<string> ret;
        while (target != -1) {
            int l = seg[target].e - seg[target].b + 1;
            string str(s.substr(seg[target].b, l));
            ret.push_back(str);
            target = step[target];
        }
        return ret;
    }
};
