class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        dist = [10**6 * 4 + 1] * n
        visited = [False] * n

        s = 0
        dist[0] = 0
        visited[0] = True
        for i in range(n):
            next_s = -1
            for j in range(n):
                if not visited[j]:
                    dist[j] = min(dist[j], abs(points[s][0] - points[j][0]) + abs(points[s][1] - points[j][1]))
                    if next_s == -1 or dist[j] < dist[next_s]:
                        next_s = j
            s = next_s
            visited[s] = True
        return sum(dist)

