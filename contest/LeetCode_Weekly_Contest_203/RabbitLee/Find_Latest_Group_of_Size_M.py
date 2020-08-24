"""
back-forward: O(nlogn)
"""
class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        groups = [[1, n]]
        if m == n:
            return n
        
        for i in range(n - 1, 0, -1):
            index = self.find_group(groups, arr[i])
            group = groups[index]
            if not group[0] <= arr[i] <= group[1]:
                continue
            if arr[i] - 1 - group[0] + 1 == m or group[1] - arr[i] - 1 + 1 == m:
                return i
            new_groups = [[group[0], arr[i] - 1], [arr[i] + 1, group[1]]]
            new_groups = [group for group in new_groups if group[1] - group[0] + 1 >= m]
            groups = (groups[:index] if index > 0 else []) + new_groups + groups[index + 1:]
            if not groups:
                break
        return -1
                
    def find_group(self, groups: List[List[int]], index: int) -> int:
        left = 0
        right = len(groups) - 1
        while left < right:
            mid = (left + right) // 2
            group = groups[mid]
            if group[0] <= index <= group[1]:
                return mid
            elif index < group[0]:
                right = mid - 1
            else:
                left = mid + 1
        return left

"""
Union Find: O(n)
"""
class Solution:
    class UnionFind:
        def __init__(self, n: int):
            self.parent = list(range(n))
            self.rank = [0] * n
        def find(self, u: int):
            self.parent[u] = self.find(self.parent[u]) if self.parent[u] != u else u
            return self.parent[u]
        def union(self, u: int, v: int) -> bool:
            pu, pv = self.find(u), self.find(v)     # parent of u, v
            if pu == pv:
                return False
            if self.rank[pu] > self.rank[pv]:
                self.parent[pv] = pu
                self.rank[pu] += self.rank[pv]
            else:
                self.parent[pu] = pv
                self.rank[pv] += self.rank[pu]
            return True
    
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        uf = self.UnionFind(n)
        ans = -1
        for step, position in enumerate(arr):
            position -= 1
            uf.rank[position] = 1
            for neigh in (position - 1, position + 1):
                if not 0 <= neigh < n:
                    continue
                if uf.rank[neigh] > 0:
                    if uf.rank[uf.find(neigh)] == m:
                        ans = step
                    uf.union(position, neigh)
        for position in range(n):
            if uf.rank[uf.find(position)] == m:
                ans = n
                break
        return ans

