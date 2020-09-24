class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1 for i in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            res = i + 1
            for coin in coins:
                if i >= coin and dp[i - coin] >= 0:
                    res = min(res, 1 + dp[i - coin])
            if res <= i:
                dp[i] = res
        return dp[amount]

