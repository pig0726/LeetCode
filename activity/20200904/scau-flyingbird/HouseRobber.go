func rob(nums []int) int {
	l := len(nums)
	if l == 0 {
		return 0
	} else if l == 1 {
		return nums[0]
	} else {
		return Max(DpRob(nums[0:l-1]), DpRob(nums[1:l]))
	}
}

func DpRob(nums []int) int {
	l := len(nums)
	if l == 1 {
		return nums[0]
	}
	pre := nums[0]
	cur := Max(nums[0], nums[1])
	for i := 2; i < l; i++ {
		pre, cur = cur, Max(pre+nums[i], cur)
	}
	return cur
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
