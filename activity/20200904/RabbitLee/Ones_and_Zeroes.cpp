class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> zeros(len, 0), ones(len, 0);
        for (int i = 0; i < len; i++) {
            int zero = 0, one = 0;
            for (auto c : strs[i]) {
                if (c == '0') zero++;
                else one++;
            }
            zeros[i] = zero;
            ones[i] = one;
        }
        vector<vector<vector<int>>> f(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zeros[i - 1] && k >= ones[i - 1] 
                        && f[i - 1][j][k] < f[i - 1][j - zeros[i - 1]][k - ones[i - 1]] + 1) {
                        f[i][j][k] = f[i - 1][j - zeros[i - 1]][k - ones[i - 1]] + 1;
                    } else {
                        f[i][j][k] = f[i - 1][j][k];
                    }
                }
            }
        }
        return f[len][m][n];
    }
};

