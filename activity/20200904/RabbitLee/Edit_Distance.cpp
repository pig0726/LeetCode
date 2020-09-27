class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) f[i][0] = i;
        for (int j = 0; j <= n; j++) f[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), 
                              f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1] ? 1 : 0));
            }
        }
        return f[m][n];
    }
};

