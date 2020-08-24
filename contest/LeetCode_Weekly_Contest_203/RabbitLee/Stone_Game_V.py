class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        f = [[0 for j in range(n)] for i in range(n)]
        s = [0]
        for v in stoneValue:
            s.append(s[-1] + v)
        s = s[1:]
        
        @functools.lru_cache(None)
        def dp(i: int, j: int) -> int:
            if i == j:
                return 0
            ans = 0
            for k in range(i, j):
                # [i..k] [k+1..j]
                left_sum = s[k] - (s[i - 1] if i > 0 else 0)
                right_sum = s[j] - s[k]
                if left_sum > right_sum:
                    ans = max(ans, right_sum + dp(k + 1, j))
                elif left_sum < right_sum:
                    ans = max(ans, left_sum + dp(i, k))
                else:
                    ans = max(ans, left_sum + dp(i, k), right_sum + dp(k + 1, j))
            return ans
        
        return dp(0, n - 1)

