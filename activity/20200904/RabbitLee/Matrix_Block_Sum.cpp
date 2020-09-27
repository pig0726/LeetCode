class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int lowX = max(0, i - K - 1), lowY = max(0, j - K - 1);
                int upX = min(m, i + K), upY = min(n, j + K);
                res[i - 1][j - 1] = s[upX][upY] - s[upX][lowY] - s[lowX][upY] + s[lowX][lowY];
            }
        }
        return res;
    }
};

