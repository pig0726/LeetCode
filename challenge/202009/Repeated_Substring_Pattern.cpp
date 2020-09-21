class Solution {
public:
    bool check(string& s, int f, int n) {
        bool flag = true;
        for (int i = f; i < n; i += f) {
            for (int k = 0; k < f; ++k) {
                if (s[i+k] != s[k]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        return flag;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if (n == 1) return false;
        for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
            if (check(s, i, n)) return true;
            if (i != 1 && check(s, n / i, n)) return true;
        }
        return false;
    }
};