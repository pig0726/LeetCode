class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        return max(self.sub_rob(nums[:n - 1]), self.sub_rob(nums[1:]))
        
    def sub_rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0, 0] for i in range(n)]
        dp[0] = [nums[0], 0]
        for i in range(1, n):
            dp[i][0] = dp[i - 1][1] + nums[i]
            dp[i][1] = max(dp[i - 1])
        return max(dp[n - 1])

