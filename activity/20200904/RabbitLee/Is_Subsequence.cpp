class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        for (int j = 0; j <= n; j++) f[0][j] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = (s[i - 1] == t[j - 1] && f[i - 1][j - 1]) || f[i][j - 1];
            }
        }
        return f[m][n];
    }
};

