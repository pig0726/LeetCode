class Solution(object):
    def getMaxLen(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        L, R, n, ret = 0, 0, len(nums), 0
        
        while L < n:
            while L < n and nums[L] == 0:
                L += 1
            R = L
            
            neg = 0
            while R < n and nums[R] != 0:
                if nums[R] < 0: 
                    neg += 1
                if neg % 2 == 0:
                    ret = max(ret, R - L + 1)
                R += 1
            
            while L < R:
                if neg % 2 == 0:
                    ret = max(ret, R - L)
                if nums[L] < 0: 
                    neg -= 1
                L += 1
                
        return ret