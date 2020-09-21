class Solution {
    int dfs(int[] cuts, int[][] dp, int n, int m, int st, int ed) {
        if (ed < st) return 0;
        if (dp[st][ed] != -1) {
            return dp[st][ed];
        }

        int L = 0, R = n;
        if (st != 0) L = cuts[st-1];
        if (ed != m-1) R = cuts[ed+1];

        int val = R - L;
        int ret = Integer.MAX_VALUE;
        dp[st][ed] = ret;
        for (int i = st; i <= ed; ++i) if (L < cuts[i] && cuts[i] < R) {
            ret = Math.min(ret,
                    dfs(cuts, dp, n, m, st, i-1) +
                    dfs(cuts, dp, n, m, i+1, ed) +
                    val);
        }

        if (ret == Integer.MAX_VALUE) ret = 0;
        dp[st][ed] = ret;
        return ret;
    }

    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int m = cuts.length;
        int[][] dp = new int[m+1][m+1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = -1;
            }
        }

        return dfs(cuts, dp, n, m,0, m-1);
    }
}
