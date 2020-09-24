class Solution {
public:
    vector<vector<int>> f;
    
    int dp(int n, int m) {
        if (n > m) swap(n, m);
        if (f[n][m] >= 0) return f[n][m];
        if (m % n == 0) return f[n][m] = m / n;
        
        int res = n * m;
        // situation 1 & 2
        for (int i = 1; i < n; i++) {
            res = min(res, dp(i, m) + dp(n - i, m));
        }
        for (int j = 1; j < m; j++) {
            res = min(res, dp(n, j) + dp(n, m - j));
        }
        // situation 3
        for (int k = 1; k <= n - 2; k++) {
            for (int i = 1; i <= n - k - 1; i++) {
                for (int j = k + 1; j <= m - 1; j++) {
                    res = min(res, dp(i, j) + dp(m - j, i + k) + dp(n - i - k, m - j + k) + dp(j - k, n - i) + 1);
                }
            }
        }
        
        return f[n][m] = res;
    }
    
    int tilingRectangle(int n, int m) {
        if (n > m) swap(n, m);
        f.resize(n + 1, vector<int>(m + 1, -1));
        return dp(n, m);
    }
};

