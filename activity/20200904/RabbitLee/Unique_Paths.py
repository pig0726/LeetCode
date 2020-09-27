from functools import lru_cache

@lru_cache(None)
def comb(a: int, b: int) -> int:
    if a == 0 or b == 0:
        return 1
    return comb(a - 1, b) + comb(a, b - 1)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return comb(m - 1, n - 1)

