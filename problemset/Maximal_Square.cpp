class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size();
        int dp[550][550];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                } else {
                    continue;
                }
                int v1 = 0, v2 = 0, v3 = 0;
                if (j-1 >= 0) v1 = dp[i][j-1];
                if (i-1 >= 0) v2 = dp[i-1][j];
                if (j-1 >= 0 && i-1 >= 0) v3 = dp[i-1][j-1];
                if (v1 && v2 && v3) {
                    dp[i][j] = max(dp[i][j], min(min(v1, v2), v3) + 1);
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret * ret;
    }
};
