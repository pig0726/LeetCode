package main

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := 0; i <= amount; i++ {
		dp[i] = amount + 1
	}
	dp[0] = 0
	for i := 1; i < len(coins); i++ {
		for j := 1; j <= amount; j++ {
			if j >= coins[i-1] {
				dp[j] = Min(dp[j], dp[j-coins[i-1]]+1)
			}
		}
	}

	if dp[amount] == amount+1 {
		return -1
	} else {
		return dp[amount]
	}
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
