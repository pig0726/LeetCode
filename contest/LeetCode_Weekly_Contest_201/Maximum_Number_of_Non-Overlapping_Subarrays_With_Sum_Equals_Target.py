class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        n = len(nums)
        dp = [0 for i in xrange(n+1)]
        pos = {0: n}
        suffix = 0
        ret = 0
        for i in xrange(n-1, -1, -1):
            suffix += nums[i]
            v = suffix - target
            dp[i] = max(dp[i], dp[i+1])
            if v in pos:
                p = pos[v]
                dp[i] = max(dp[i], dp[p]+1)
            pos[suffix] = i
            ret = max(ret, dp[i])
        return ret
        
