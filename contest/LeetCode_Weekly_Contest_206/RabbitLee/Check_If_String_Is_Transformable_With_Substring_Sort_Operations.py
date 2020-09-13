class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        n = len(s)
        posi = [n] * 10
        for i, c1 in enumerate(s):
            v = ord(c1) - ord('0')
            if posi[v] == n:
                posi[v] = i
        for c2 in t:
            v = ord(c2) - ord('0')
            if posi[v] == n:
                return False
            for i in range(v):
                if posi[i] < posi[v]:
                    return False
            posi[v] += 1
            while posi[v] < n and s[posi[v]] != c2:
                posi[v] += 1
        return True

