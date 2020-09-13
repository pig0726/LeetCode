class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        res = set()
        for i, pair in enumerate(pairs):
            x, y = pair[0], pair[1]
            for j, pair2 in enumerate(pairs[i + 1:]):
                u, v = pair2[0], pair2[1]
                if preferences[x].index(u) < preferences[x].index(y) \
                    and preferences[u].index(x) < preferences[u].index(v):
                    res.add(x)
                    res.add(u)
                u, v = v, u
                if preferences[x].index(u) < preferences[x].index(y) \
                    and preferences[u].index(x) < preferences[u].index(v):
                    res.add(x)
                    res.add(u)

            x, y = y, x
            for j, pair2 in enumerate(pairs[i + 1:]):
                u, v = pair2[0], pair2[1]
                if preferences[x].index(u) < preferences[x].index(y) \
                    and preferences[u].index(x) < preferences[u].index(v):
                    res.add(x)
                    res.add(u)
                u, v = v, u
                if preferences[x].index(u) < preferences[x].index(y) \
                    and preferences[u].index(x) < preferences[u].index(v):
                    res.add(x)
                    res.add(u)
        return len(res)

