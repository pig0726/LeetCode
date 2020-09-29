func getMaximumGold(grid [][]int) int {
	// 边界判断
	if grid == nil || len(grid) == 0 {
		return 0
	}

	var res float64

	// 循环每一个点，找到最大值
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			res = math.Max(res, dfs(grid, i, j))
		}
	}

	return int(res)
}

func dfs(grid [][]int, x, y int) float64 {
	// 结束条件
	if x < 0 || y < 0 || x >= len(grid) || y >= len(grid[0]) || grid[x][y] == 0 {
		return 0
	}

	// 保存当前节点值，回溯算法
	temp := grid[x][y]

	// 递归查找上下左右四个方向
	grid[x][y] = 0
	up := dfs(grid, x-1, y)
	down := dfs(grid, x+1, y)
	left := dfs(grid, x, y-1)
	right := dfs(grid, x, y+1)

	// 上下左右四个方向的最大值
	var res float64
	res = math.Max(res, left)
	res = math.Max(res, right)
	res = math.Max(res, up)
	res = math.Max(res, down)

	grid[x][y] = temp

	// 加上当前grid的值
	return res + float64(grid[x][y])
}
