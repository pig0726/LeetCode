class Solution(object):
    def dfs(self, st, ed):
        if ed < st: return 0
        
        if self.dp[st][ed] != -1:
            return self.dp[st][ed]
        
        L, R = 0, self.n
        if st != 0: 
            L = self.cuts[st-1]
        if ed != self.m-1: 
            R = self.cuts[ed+1]
        
        val, ret = R - L, 1<<32
        
        for i in xrange(st, ed+1):
            if L < self.cuts[i] and self.cuts[i] < R:
                ret = min(ret, self.dfs(st, i-1) + self.dfs(i+1, ed) + val)
        
        if ret == 1<<32:
            ret = 0
        self.dp[st][ed] = ret
        return ret
        
    def minCost(self, n, cuts):
        """
        :type n: int
        :type cuts: List[int]
        :rtype: int
        """
        cuts.sort()
        self.n = n
        self.m = len(cuts)
        self.cuts = cuts
        self.dp = [[-1 for _ in range(self.m)] for _ in xrange(self.m)]
        
        return self.dfs(0, self.m-1)
        
