func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, stone := range stones {
		sum += stone
	}
	target := sum / 2
	dp := make([]int, target+1)
	for _, stone := range stones {
		for j := target; j >= stone; j-- {
			dp[j] = Max(dp[j], dp[j-stone]+stone)
		}
	}
	return sum - 2*dp[target]
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
