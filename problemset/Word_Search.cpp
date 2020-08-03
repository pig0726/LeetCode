class Solution {
public:
    bool vis[1010][1010];
    
    const int dr[4] = {0, -1, 0, 1};
    const int dc[4] = {-1, 0, 1, 0};
    
    bool dfs(int r, int c, int row, int col, vector<vector<char> >& board, int i, int n, string& word) {      
        if (board[r][c] != word[i]) return false;
        if (i == n-1) return true;
            
        vis[r][c] = true;
        for (int k = 0; k < 4; k++) {
            int rr = r + dr[k];
            int cc = c + dc[k];
            if (rr < 0 || rr >= row) continue;
            if (cc < 0 || cc >= col) continue;
            if (vis[rr][cc]) continue;
            
            bool ret = dfs(rr, cc, row, col, board, i+1, n, word);
            if (ret) return ret;
        }
        vis[r][c] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        if (!n) return true;
        
        int row = board.size();
        if (!row) return false;
        
        int col = board[0].size();
        if (!col) return false;
        
        memset(vis, false, sizeof vis);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool ret = dfs(i, j, row, col, board, 0, n, word);
                if (ret) return true;
            }
        }
        
        return false;
    }
};
