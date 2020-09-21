class Solution(object):
    def maxDistance(self, p, m):
        """
        :type position: List[int]
        :type m: int
        :rtype: int
        """
        p.sort()
        
        def check(dist):
            cnt, pre, n = 1, p[0], len(p)
            for i in xrange(1, n):
                if p[i] - pre >= dist:
                    pre = p[i]
                    cnt += 1
                if cnt == m:
                    return True
            return False
        
        low, hight, ans = 0, 1000000000, 0
        while low <= hight:
            mid = (low + hight) >> 1
            if check(mid):
                ans = mid
                low = mid + 1
            else:
                hight = mid - 1
        return ans
        
