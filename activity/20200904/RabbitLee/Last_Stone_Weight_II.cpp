class Solution {
public:
    vector<vector<bool>> f;
    int n;
        
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        n = stones.size();
        f.resize(n + 1, vector<bool>(sum + 1, false));
        for (int j = 1; j <= sum; j++) f[0][j] = false;
        for (int i = 0; i <= n; i++) f[i][0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= stones[i - 1]) f[i][j] = f[i][j] || f[i - 1][j - stones[i - 1]];
            }
        }
        
        for (int j = sum / 2; j >= 1; j--) {
            if (f[n][j]) return (sum - j) - j;
        }
        return sum;
    }
};

