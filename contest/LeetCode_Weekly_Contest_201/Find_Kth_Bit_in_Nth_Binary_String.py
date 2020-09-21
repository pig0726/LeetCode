class Solution(object):
    def findKthBit(self, n, k):
        ret = [0]
        n -= 1
        k -= 1
        
        for i in xrange(0, n):
            b = map(lambda c: 0 if c else 1, ret[-1::-1])
            ret.append(1)
            ret.extend(b)
        return str(ret[k])
        
