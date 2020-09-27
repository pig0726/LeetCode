class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') f[0][j] = true;
            else break;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*' && j >= 2) {
                    f[i][j] = f[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') 
                        f[i][j] = f[i][j] || f[i - 1][j];
                } else if (p[j - 1] == '.') {
                    f[i][j] = f[i - 1][j - 1];
                } else { // a-z
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};

