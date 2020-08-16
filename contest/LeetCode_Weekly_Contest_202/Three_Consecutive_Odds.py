class Solution(object):
    def threeConsecutiveOdds(self, a):
        """
        :type arr: List[int]
        :rtype: bool
        """
        return any(map(lambda st: a[st]&1 and a[st+1]&1 and a[st+2]&1, [i for i in xrange(len(a)-2)]))
