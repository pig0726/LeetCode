func climbStairs(n int) int {
	dp := []int{0, 1, 2}
	for i := 3; i <= 45; i++ {
		dp = append(dp, dp[i-1]+dp[i-2])
	}
	return dp[n]
}
