class Solution(object):
    MOD = 1000000007
    
    def dfs(self, nums):
        if len(nums) <= 1: return 1
        
        a, b = [], []
        for x in nums:
            if x == nums[0]: 
                continue
            if x < nums[0]: 
                a.append(x)
            else:
                b.append(x)
                
        return (self.f[len(a)][len(b)] * self.dfs(a) * self.dfs(b)) % self.MOD
        
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        self.n = len(nums)
        
        self.f = [[0 for _ in xrange(self.n + 1)] for _ in xrange(self.n + 1)]
        for i in xrange(self.n+1):
            self.f[i][0] = self.f[0][i] = 1
            
        for i in xrange(1, self.n+1):
            for j in xrange(1, self.n+1):
                self.f[i][j] = (self.f[i-1][j] + self.f[i][j-1]) % self.MOD
                
        ret = self.dfs(nums)
        return (ret - 1 + self.MOD) % self.MOD