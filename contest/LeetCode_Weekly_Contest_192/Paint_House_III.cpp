const int M = 105;
const int N = 25;
const int INF = 0x3f3f3f3f;
int dp[M][M][N];

class Solution {
public:
    void udp(int& a, int x) {
        if (x >= INF) return;
        a = min(a,x);
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, 0x3f, sizeof dp);
        int stc = -1, edc = -1, painted = -1;
        if (houses[0]) stc = edc = houses[0], painted = 1;
        else stc = 1, edc = n, painted = 0;
        
        //printf("st0=%d, ed0=%d\n", stc, edc);
        for (int i = stc; i <= edc; ++i) {
            int ct = 0;
            if (!painted) ct = cost[0][i-1];
            dp[0][1][i] = ct;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= min(i+1, target); ++j) {
                int stc = -1, edc = -1, painted = -1;
                if (houses[i]) stc = edc = houses[i], painted = 1;
                else stc = 1, edc = n, painted = 0;
                for (int c = stc; c <= edc; ++c) {
                    int ct = 0;
                    if (!painted) ct = cost[i][c-1];
                    udp(dp[i][j][c], dp[i-1][j][c]+ct);
                    
                    
                    for (int cc = 1; cc <= n; ++cc) if (cc != c) {
                        udp(dp[i][j][c], dp[i-1][j-1][cc] + ct);
                    }
                    //printf("dp %d %d %d = %d\n", i, j, c, dp[i][j][c]);
                }
            }
        }
        
        int ret = INF;
        for (int c = 1; c <= n; ++c)
            ret = min(ret, dp[m-1][target][c]);
        if (ret == INF) ret = -1;
        return ret;
            
    }
};
