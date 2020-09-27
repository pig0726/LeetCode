class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<long long>>f (n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) f[i][0] = startFuel;
        for (int i = 1; i <= n; i++) {
            int distance = stations[i - 1][0];
            int fuel = stations[i - 1][1];
            for (int j = 1; j <= i; j++) {
                f[i][j] = f[i - 1][j];
                if (f[i - 1][j - 1] >= distance) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + fuel);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            if (f[n][j] >= target) return j;
        }
        return -1;
    }
};

