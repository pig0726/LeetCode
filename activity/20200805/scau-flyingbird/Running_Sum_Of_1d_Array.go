func runningSum(nums []int) []int {
	length := len(nums)
	sum := 0
	for i := 0; i < length; i++ {
		nums[i] = nums[i] + sum
		sum = nums[i]
	}
	return nums
}
