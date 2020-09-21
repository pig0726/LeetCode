class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> pos = new HashMap<Integer, Integer>();

        int[] dp = new int[n+1];
        for (int i = 0; i <= n; ++i) dp[i] = 0;
        pos.put(0, n);

        int suffix = 0, ret = 0;

        for (int i = n-1; i >= 0; --i) {
            dp[i] = Math.max(dp[i], dp[i+1]);
            suffix += nums[i];
            int v = suffix - target;
            if (pos.containsKey(v)) { 
                int p = pos.get(v);
                dp[i] = Math.max(dp[i], dp[p] + 1);
            }
            pos.put(suffix, i);
            ret = Math.max(ret, dp[i]);
        }
        return ret;
    }
}
