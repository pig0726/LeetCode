class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret1 = "1"
        ret2 = []
        for turn in xrange(2, n+1):
            length, cnt = len(ret1), 0
            for i in xrange(length):
                if i == 0:
                    cnt = 1
                elif ret1[i] == ret1[i-1]:
                    cnt += 1
                else:
                    ret2.extend([str(cnt), str(ret1[i-1])])
                    cnt = 1
            ret2.extend([str(cnt), str(ret1[-1])])
            ret1 = "".join(ret2)
            ret2 = []

        return ret1



