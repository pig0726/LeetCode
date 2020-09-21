class Solution {
    int[][] f;
    int[] s;
    
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        f = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            f[i][i] = 0;
        }
        s = new int[n];
        s[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            s[i] = s[i - 1] + stoneValue[i];
        }
        return dp(0, n - 1);
    }
    
    int dp(int i, int j) {
        if (f[i][j] >= 0) return f[i][j]; 
        int ans = 0;
        for (int k = i; k < j; k++) {
            int leftSum = s[k] - (i > 0 ? s[i - 1] : 0);
            int rightSum = s[j] - s[k];
            if (leftSum > rightSum) {
                ans = Math.max(ans, rightSum + dp(k + 1, j));
            } else if (leftSum < rightSum) {
                ans = Math.max(ans, leftSum + dp(i, k));
            } else {
                ans = Math.max(Math.max(ans, leftSum + dp(i, k)), rightSum + dp(k + 1, j));
            }
        }
        f[i][j] = ans;
        return ans;
    }
}

