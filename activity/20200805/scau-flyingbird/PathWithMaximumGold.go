func getMaximumGold(grid [][]int) int {
	max, rows, cols := 0, len(grid), len(grid[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			max = Max(max, getGold(&grid, rows, cols, i, j))
		}
	}
	return max
}

func getGold(grid *([][]int), rows int, cols int, x int, y int) int {
	if x < 0 || x > rows-1 || y < 0 || y > cols-1 || (*grid)[x][y] == 0 {
		return 0
	} else {
		tmp := (*grid)[x][y]
		(*grid)[x][y] = 0
		max := tmp + Max4(getGold(grid, rows, cols, x, y-1), getGold(grid, rows, cols, x, y+1), getGold(grid, rows, cols, x-1, y), getGold(grid, rows, cols, x+1, y))
		(*grid)[x][y] = tmp
		return max
	}
}

func Max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func Max4(a int, b int, c int, d int) int {
	return Max(a, Max(b, Max(c, d)))
}

