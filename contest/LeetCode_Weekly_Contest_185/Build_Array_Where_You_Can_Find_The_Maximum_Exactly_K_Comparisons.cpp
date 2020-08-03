using ll = long long;
const int mod = 1e9+7;

ll f[55][105][55];


class Solution {
public:
    int numOfArrays(int N, int M, int K) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= M; ++i)
            f[0][i][1] = 1;
        for (int i = 0; i < N-1; ++i) {
            for (int j = 1; j <= M; ++j) {
                for (int k = 1; k <= K; ++k) {
                    const ll& pre = f[i][j][k];
                    f[i+1][j][k] = (f[i+1][j][k] + pre * j) % mod;
                    for (int x = j+1; x <= M; ++x) {
                        f[i+1][x][k+1] = (f[i+1][x][k+1] + pre) % mod;
                    }
                }
            }
        }
        ll ret = 0;
        for (int j = 1; j <= M; ++j) ret = (ret + f[N-1][j][K]) % mod;
        return ret;
    }
};
