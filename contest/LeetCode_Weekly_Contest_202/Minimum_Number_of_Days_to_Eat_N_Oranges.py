class Solution(object):
    def minDays(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        dp = {}
        
        def dfs(n):
            if n == 0: return 0
            elif n == 1: return 1
            elif n == 2: return 2
            
            if n in dp: return dp[n]
            
            ret = min(dfs(n / 3) + n % 3, dfs(n / 2) + n % 2) + 1
            dp[n] = ret
            
            return ret
        
        return dfs(n)
