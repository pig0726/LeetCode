class Solution {
    static final int[] dr = {0, -1, 0, 1};
    static final int[] dc = {-1, 0, 1, 0};

    static final int N = 35;
    boolean[][] vis  = new boolean[N][N];
    int n = 0, m = 0, cnt = 0;

    void dfs(int[][] grid, int r, int c) {
        vis[r][c] = true;
        cnt++;
        for (int k = 0; k < 4; ++k) {
            int x = r + dr[k];
            int y = c + dc[k];
            if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 1 && !vis[x][y])
                dfs(grid, x, y);
        }
    }

    boolean check(int[][] grid, int tot) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) if (grid[i][j] == 1) {
                cnt = 0;
                dfs(grid, i, j);
                if (cnt != tot) return true;
                else return false;
            }
        return false;
    }

    public int minDays(int[][] grid) {
        n = grid.length;
        m = grid[0].length;


        int onecnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) onecnt++;

        if (onecnt == 1) return 1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                vis[i][j] = false;

        if (check(grid, onecnt)) return 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) if (grid[i][j] == 1) {
                vis = new boolean[N][N];
                grid[i][j] = 0;
                if (check(grid,onecnt-1)) return 1;
                grid[i][j] = 1;
            }

        return 2;
    }
}