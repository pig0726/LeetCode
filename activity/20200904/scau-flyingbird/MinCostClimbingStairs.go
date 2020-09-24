func minCostClimbingStairs(cost []int) int {
	l := len(cost)
	if l == 0 {
		return 0
	} else if l == 1 {
		return cost[0]
	}
	dp := make([]int, l)
	dp[0] = cost[0]
	dp[1] = Min(cost[0], cost[1])
	for i := 2; i < l; i++ {
		dp[i] = Min(dp[i-1], dp[i-2]+cost[i])
	}
	return dp[l-1]
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
