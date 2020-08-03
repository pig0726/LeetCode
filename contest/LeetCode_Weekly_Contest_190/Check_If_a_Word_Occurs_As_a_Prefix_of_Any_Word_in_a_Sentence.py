class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord): 
        parts = sentence.split(" ")
        ans = -1
        n = len(parts)
        for i in xrange(0, n):
            if parts[i].startswith(searchWord):
                ans = i+1
                break;
        return ans
        
