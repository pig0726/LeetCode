class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
                    if (f[i][j] > res) res = f[i][j];
                }
            }
        }
        return res * res;
    }
};

