class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int p = 101;
                for (int k = -1; k <= 1; k++) {
                    if (j + k >= 0 && j + k < n && p > A[i - 1][j + k]) p = A[i - 1][j + k];
                }
                A[i][j] += p;
            }            
        }
        return *min_element(A[m - 1].begin(), A[m - 1].end());
    }
};

