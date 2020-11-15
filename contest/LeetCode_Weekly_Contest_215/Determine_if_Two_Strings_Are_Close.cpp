class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt(26);
        for (char c : word2) cnt[c - 'a']++;
        
        vector<int> data(26);
        for (char c : word1) data[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            int t = cnt[i];
            if (data[i] == t) continue;
            if (t == 0 || data[i] == 0) return false;
            int idx = -1;
            for (int k = i+1; k < 26; k++) if (data[k] == t) {
                idx = k;
                swap(data[i], data[k]);
                break;
            }
            if (idx == -1) return false;
        }
        
        return true;
    }
};
