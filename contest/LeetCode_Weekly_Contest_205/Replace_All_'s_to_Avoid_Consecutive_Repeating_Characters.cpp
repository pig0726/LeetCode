class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for (int i = 0; i < n; ++i) if (s[i] == '?') {
            char c = 0;
            for (int k = 0; k < 26; ++k) {
                if ((i-1 < 0 || s[i-1] != 'a' + k) && (i+1 >= n || s[i+1] != 'a' + k)) {
                    c = k + 'a';
                    break;
                }
            }
            s[i] = c;
        }
        return s;
    }
};