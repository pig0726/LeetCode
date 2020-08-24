class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n = len(piles) // 3
        piles = sorted(piles, reverse=True)[:2*n][1::2]
        return sum(piles)

