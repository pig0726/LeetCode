const int N = 52;
const int K = 12;
const int MOD = 1e9+7;
using ll = long long;
ll dp[N][N][K];

class Solution {
public:
    int n, m;
    vector<vector<int>> msum;

    int getsum(int r, int c, int r1, int c1) {
        return msum[r1][c1] - msum[r1][c-1] -
            msum[r-1][c1] + msum[r-1][c-1];
    }

    ll dfs(int r, int c, int re) {
        if (dp[r][c][re] != -1) return dp[r][c][re];

        ll& ret = dp[r][c][re];
        ret = 0;

        if (re == 1) {
            int sum = getsum(r, c, n, m);
            if (sum) ret = 1;
            return ret;
        }

        for (int r1 = r+1; r1 <= n; ++r1) {
            int up_sum = getsum(r, c, r1-1, m);
            if (!up_sum) continue;
            ll tmp = dfs(r1, c, re-1);
            ret = (ret + tmp) % MOD;
        }

        for (int c1 = c+1; c1 <= m; ++c1) {
            int left_sum = getsum(r, c, n, c1-1);
            if (!left_sum) continue;
            ll tmp = dfs(r, c1, re-1);
            ret = (ret + tmp) % MOD;
        }
        return ret;
    }

    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza.front().size();
        msum.assign(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                msum[i][j] = msum[i][j-1] + msum[i-1][j] -
                    msum[i-1][j-1] + (pizza[i-1][j-1] == 'A');
            }
        }

        memset(dp, -1, sizeof(dp));
        dfs(1, 1, k);
        return dp[1][1][k];
    }
};