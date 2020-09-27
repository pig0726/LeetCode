//dp[i] = dp[i-1] > 0? dp[i-1] + nums[i] : nums[i]
func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	max := nums[0]
	dp := nums[0]
	for i := 1; i < len(nums); i++ {
		if dp > 0 {
			dp = dp + nums[i]
		} else {
			dp = nums[i]
		}
		max = Max(dp, max)
	}
	return max
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
