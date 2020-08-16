class Solution(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        # mid = (1 + 2*(n-1)+1)/2 = n
        return sum(map(lambda idx: n - 2*idx-1, [i for i in xrange((n+1)>>1)]))
        
