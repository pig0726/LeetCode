func rob(nums []int) int {
	l := len(nums)
	if l == 0 {
		return 0
	} else if l == 1 {
		return nums[0]
	}
	dp := make([]int, l+1)
	dp[0] = nums[0]
	dp[1] = Max(nums[0], nums[1])
	for i := 2; i < l; i++ {
		dp[i] = Max(dp[i-2]+nums[i], dp[i-1])
	}
	return dp[l-1]
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
