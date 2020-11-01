class Solution(object):
    
    def calc(self, h, v):
        m = h + v
        A = 1
        for i in xrange(2, m+1):
            A *= i
        ah = 1
        for i in xrange(2, h+1):
            ah *= i
            
        av = 1
        for i in xrange(2, v+1):
            av *= i
            
        return A / ah / av
    
    def kthSmallestPath(self, dest, k):
        """
        :type destination: List[int]
        :type k: int
        :rtype: str
        """
        
        H, V = dest[1], dest[0]
        
        n = H + V
        ret = ['0' for _ in xrange(n)]
        for i in xrange(0, n):
            if H > 0:
                s = self.calc(H-1, V)
                if s >= k:
                    ret[i] = 'H'
                    H -= 1
                else:
                    ret[i] = 'V'
                    k -= s
                    V -= 1
            else:
                ret[i] = 'V'
        
        return ''.join(ret)
        
