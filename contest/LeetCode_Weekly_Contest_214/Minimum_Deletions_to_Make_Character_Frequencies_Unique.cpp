class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        
        map<int, int> m;
        for (int i = 0; i < 26; i++) 
            if (cnt[i]) m[-cnt[i]]++;
    
        int ret = 0;
        while (true) { 
            int k = 1, v = 0;
            for (const auto& p : m) {
                if (p.second == 1) continue;
                k = p.first;
                v = p.second;
                break;
            }
            if (k == 1) break;
            if (v > 1) ret += v - 1;
            if (v > 1 && k + 1 != 0)
                m[k + 1] += v - 1;
            m[k] = 1;
        }
        return ret;
    }
};
