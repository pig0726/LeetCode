class Solution(object):
    def makeGood(self, s):
        """
        :type s: str
        :rtype: str
        """
        ret = []
        for c in s:
            if len(ret) and \
               ((ret[-1].islower() and c.isupper() and ret[-1] == c.lower()) or
                (ret[-1].isupper() and c.islower() and ret[-1].lower() == c)):
                ret.pop(-1)
            else: ret.append(c)
                
        return "".join(ret)
        
