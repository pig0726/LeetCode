class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = list()
        for num in range(left, right + 1):
            if self.isSelfDividingNumber(num):
                ans.append(num)
        return ans
        
    def isSelfDividingNumber(self, num: int) -> bool:
        num2 = num
        while num2 > 0:
            digit = num2 % 10
            if digit == 0 or num % digit != 0:
                return False
            num2 //= 10
        else:
            return True

