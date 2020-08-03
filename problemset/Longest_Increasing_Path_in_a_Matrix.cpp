class Solution {
public:
    const int dx[4] = {0, -1, 0, 1};
    const int dy[4] = {-1, 0, 1, 0};

    int dp[1010][1010];
    int ret;

    void dfs(int r, int c, const vector<vector<int> >& m, const int row, const int col) {
        if (dp[r][c] != -1) return;

        dp[r][c] = 0;
        for (int d = 0; d < 4; d++) {
            int r_ = r + dx[d];
            int c_ = c + dy[d];
            if (r_ < 0 || r_ >= row || c_ < 0 || c_ >= col || m[r_][c_] <= m[r][c]) continue;
            dfs(r_, c_, m, row, col);
            dp[r][c] = max(dp[r][c], dp[r_][c_]);
        }
        ++dp[r][c];
        ret = max(ret, dp[r][c]);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        if (!col) return 0;

        ret = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                dfs(i, j, matrix, row, col);
        return ret;
    }
};
