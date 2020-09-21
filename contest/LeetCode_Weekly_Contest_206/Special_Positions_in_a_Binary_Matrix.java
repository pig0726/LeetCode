class Solution {
    public int numSpecial(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int ret = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) if (mat[i][j] == 1) {
                boolean flag = true;
                for (int c = 0; c < m; ++c) if (c != j && mat[i][c] == 1) {
                    flag = false;
                    break;
                }
                if (!flag) continue;
                for (int r = 0; r < n; ++r) if (r != i && mat[r][j] == 1) {
                    flag = false;
                    break;
                }
                if (flag) ret++;
            }
        return ret;
    }
}

