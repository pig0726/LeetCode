func getMaximumGold(grid [][]int) int {
	rows := len(grid)
	cols := len(grid[0])
	maxSum := 0

	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if grid[r][c] != 0 {
				count := dfs(&grid, r, c)
				maxSum = Max(count, maxSum)
			}
		}
	}

	return maxSum

}

func dfs(grid *[][]int, r, c int) int {
	if r < 0 || r >= len(*grid) || c < 0 || c >= len((*grid)[0]) || (*grid)[r][c] == 0 {
		return 0
	}
	sum := (*grid)[r][c]
	val := (*grid)[r][c]
	(*grid)[r][c] = 0
	sum += Max(dfs(grid, r-1, c), Max(dfs(grid, r+1, c), Max(dfs(grid, r, c-1), dfs(grid, r, c+1))))
	(*grid)[r][c] = val
	return sum

}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

