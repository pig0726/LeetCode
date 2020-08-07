class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        s = 0
        
        while n > 0:
            digit = n % 10
            product *= digit
            s += digit
            n //= 10
        
        return product - s

