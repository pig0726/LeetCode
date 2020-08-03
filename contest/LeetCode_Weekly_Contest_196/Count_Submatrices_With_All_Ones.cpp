class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();
        
        vector<vector<int> > f(n, vector<int>(m));
        
        for (int r = 0; r < n; ++r) {
            int p = m;
            for (int c = m-1; c >= 0; --c) {
                if (!mat[r][c]) p = c;
                else f[r][c] = p;
                
            }
        }
        
        int ret = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (!mat[r][c]) continue;
                
                int len = INT_MAX;
                for (int rr = r; rr < n && mat[rr][c]; ++rr) {
                    len = min(len, f[rr][c] - c);
                    ret += len;
                }
            }
        }
        
        return ret;
    }
};
