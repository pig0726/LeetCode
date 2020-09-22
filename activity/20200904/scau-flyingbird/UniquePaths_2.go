func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	rows, cols := len(obstacleGrid), len(obstacleGrid[0])
	//start or end is 1 return 0
	if obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1 {
		return 0
	}

	//init obstacleGrid[0][...] row value
	for i := 0; i < cols; i++ {
		if obstacleGrid[0][i] == 1 {
			for ; i < cols; i++ {
				obstacleGrid[0][i] = 0
			}
		} else {
			obstacleGrid[0][i] = 1
		}
	}

	//init obstacleGrid[...][0] col value
	for i := 1; i < rows; i++ {
		if obstacleGrid[i][0] == 1 {
			for ; i < rows; i++ {
				obstacleGrid[i][0] = 0
			}
		} else {
			obstacleGrid[i][0] = 1
		}
	}

	//dp
	for i := 1; i < rows; i++ {
		for j := 1; j < cols; j++ {
			if obstacleGrid[i][j] == 1 {
				obstacleGrid[i][j] = 0
			} else {
				obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]
			}
		}
	}
	return obstacleGrid[rows-1][cols-1]
}

