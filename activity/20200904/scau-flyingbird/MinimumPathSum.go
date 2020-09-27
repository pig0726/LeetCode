func minPathSum(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	rows, cols := len(grid), len(grid[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				grid[0][j] = grid[0][j-1] + grid[0][j]
			} else if j == 0 {
				grid[i][j] = grid[i-1][j] + grid[i][j]
			} else {
				grid[i][j] = Min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
			}
		}
	}
	return grid[rows-1][cols-1]
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
