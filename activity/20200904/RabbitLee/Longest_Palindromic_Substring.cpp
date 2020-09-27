class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            f[i][i] = true;
            f[i][i + 1] = s[i] == s[i + 1];
        }
        f[n - 1][n - 1] = true;
        for (int k = 2; k < n; k++) {
            for (int i = 0, j = i + k; j < n; i++, j++) {
                f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
            }
        }
        for (int k = n - 1; k >= 0; k--) {
            for (int i = 0, j = i + k; j < n; i++, j++) {
                if (f[i][j]) {
                    return s.substr(i, k + 1);
                }
            }
        }
        return "";
    }
};

