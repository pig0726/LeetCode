func uniquePaths(m int, n int) int {
	var dp [2][100]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				dp[i%2][j] = 1
			} else {
				dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j]
			}
		}
	}
	return dp[(m-1)%2][n-1]
}
