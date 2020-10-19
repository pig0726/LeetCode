class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        int st0 = 0, ed0 = 10;
        int st1 = 0, ed1 = 1;
        if (b & 1) ed1 = 10;

        string ret = s;
        for (int a0 = st0; a0 < ed0; a0++) {
            for (int a1 = st1; a1 < ed1; a1++) {
                string tmp = s;
                for (int i = 1; i < n; i += 2) {
                    tmp[i] = ((tmp[i]-'0' + a0 * a) % 10) + '0';
                }
                for (int i = 0; i < n; i += 2) {
                    tmp[i] = ((tmp[i]-'0' + a1 * a) % 10) + '0';
                }
            
                for (int t = 0; t < n; t++) {
                    int len = (t * b) % n;
                    string tmp2 = tmp.substr(n-len, len) + tmp.substr(0, n - len);
                    ret = min(ret, tmp2);
                }
            }
        }
        return ret;
    }
};
