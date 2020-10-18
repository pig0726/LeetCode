class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int p0[26];
        int p1[26];
        for (int i = 0; i < 26; i++) {
            p0[i] = s.length() + 1;
            p1[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            p0[idx] = min(p0[idx], i);
            p1[idx] = max(p1[idx], i);
        }
        
        int ret = -1;
        for (int i = 0; i < 26; i++) {
            if (p0[i] == s.length() + 1 || p1[i] == -1)
                continue;
            int len = p1[i] - p0[i] - 1;
            ret = max(ret, len);
        }
        return ret;
    }
};
