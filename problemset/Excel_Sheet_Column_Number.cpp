class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0, base = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i != s.length() - 1) base *= 26;
            ret += (s[i] - 'A' + 1) * base;
        }
        return ret;
    }
};
