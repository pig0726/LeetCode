class Solution(object):
    dr = [0, -1, 0, 1]
    dc = [-1, 0, 1, 0]
    
    def dfs(self, r, c):
        self.vis[r][c] = 1
        self.cnt += 1
        
        for k in xrange(4):
            x = r + self.dr[k]
            y = c + self.dc[k]
            if 0 <= x and x < self.n and 0 <= y and y < self.m and self.grid[x][y] and not self.vis[x][y]:
                self.dfs(x, y)
        
    def check(self, tot):
        self.vis = [[0 for _ in xrange(self.m)] for _ in xrange(self.n)]
        self.cnt = 0
        for i in xrange(0, self.n):
            for j in xrange(0, self.m):
                if self.grid[i][j]:
                    self.dfs(i, j)
                    if self.cnt != tot:
                        return True
                    else:
                        return False
        return False
    
    def minDays(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        self.n = len(grid)
        self.m = len(grid[0])
        self.grid = grid
        
        onecnt = 0
        for i in xrange(0, self.n):
            for j in xrange(0, self.m):
                if self.grid[i][j]: 
                    onecnt += 1
        
        if self.check(onecnt):
            return 0
        
        if onecnt == 1:
            return 1
        
        for i in xrange(0, self.n):
            for j in xrange(0, self.m):
                if self.grid[i][j]:
                    self.grid[i][j] = 0
                    if self.check(onecnt - 1):
                        return 1
                    self.grid[i][j] = 1
        return 2