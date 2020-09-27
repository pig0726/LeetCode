class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        dp = [[0, 0] for i in range(n)]
        dp[0] = [nums[0], 0]
        for i in range(1, n):
            dp[i][0] = dp[i - 1][1] + nums[i]
            dp[i][1] = max(dp[i - 1])
        return max(dp[n - 1])

