class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();
        
        int ret = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) if (mat[i][j]) {
                bool flag = true;
                for (int c = 0; c < m; ++c) if (c != j && mat[i][c]) {
                    flag = false;
                    break;
                }
                if (!flag) continue;
                for (int r = 0; r < n; ++r) if (r != i && mat[r][j]) {
                    flag = false;
                    break;
                }
                if (flag) ret++;
            }
        return ret;
    }
};
