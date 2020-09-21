const int N = 35;
bool vis[N][N];


class Solution {
public:
    int n, m, onecnt, cnt;
    vector<vector<int>> grid;
    const int dr[4]{0, -1, 0, 1};
    const int dc[4]{-1, 0, 1, 0};
    
    void dfs(int r, int c) {
        vis[r][c] = true;
        cnt++;
        for (int k = 0; k < 4; ++k) {
            int x = r + dr[k];
            int y = c + dc[k];
            if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] && !vis[x][y])
                dfs(x, y);
        }
    }
    
    bool check(const int tot) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) if (grid[i][j]) {
                cnt = 0;
                dfs(i, j);
                if (cnt != tot) return true;
                else return false;
            }
        return false;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid.front().size();
        this->grid = grid;
        
        onecnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) onecnt++;
        
        if (onecnt == 1) return 1;
        
        memset(vis, 0, sizeof vis);
        if (check(onecnt)) return 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) if (grid[i][j]) {
                memset(vis, 0, sizeof vis);
                this->grid[i][j] = 0;
                if (check(onecnt-1)) return 1;
                this->grid[i][j] = 1;
            }
        
        return 2;
    }
};
