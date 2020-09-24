class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        f = [[0 for j in range(n)] for i in range(m)]
        f[0][0] = 1 if obstacleGrid[0][0] == 0 else 0
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 0:
                    f[i][j] += (f[i - 1][j] if i > 0 else 0) + (f[i][j - 1] if j > 0 else 0)
        return f[m - 1][n - 1]

