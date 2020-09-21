class Solution(object):
    def containsPattern(self, arr, m, k):
        """
        :type arr: List[int]
        :type m: int
        :type k: int
        :rtype: bool
        """
        
        n, cnt = len(arr), m * k
        for i in xrange(0, n+1-cnt):
            flag = True
            for j in xrange(i, i+cnt, m):
                for k in xrange(0, m):
                    if arr[i+k] != arr[j+k]:
                        flag = False
                        break
                if not flag: break
            if flag: return True
        return False