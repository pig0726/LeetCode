class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        vector<int> maxpos(26, -1);
        for (int i = 0; i < n; ++i) {
            int id = S[i] - 'a';
            maxpos[id] = max(maxpos[id], i);
        }
        
        vector<int> ret;
        int l = 0, r = 0, pos = maxpos[S[0]-'a'];
        
        while (l < n && r < n) {
            int p = maxpos[S[r] - 'a'];
            pos = max(pos, p);
            if (r == pos) {
                ret.push_back(r - l + 1);
                l = r = r + 1;
            } else ++r;
        }
        
        return ret;
    }
};