class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] > 0:
                    ans = max(ans, self.getMaximumGoldFrom(grid, i, j))
        return ans
        
    def getMaximumGoldFrom(self, grid: List[List[int]], x: int, y: int) -> int:
        ans = 0
        grid[x][y] = -grid[x][y]
        next_points = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        for next_point in next_points:
            next_x = x + next_point[0]
            next_y = y + next_point[1]
            if 0 <= next_x < len(grid) and 0 <= next_y < len(grid[0]) and \
                grid[next_x][next_y] > 0:
                ans = max(ans, self.getMaximumGoldFrom(grid, next_x, next_y))
        grid[x][y] = -grid[x][y]
        return ans + grid[x][y]

