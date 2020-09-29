func moveZeroes(nums []int)  {
	start := 0
	for _, value := range nums {
		if value != 0 {
			nums[start] = value
			start++
		}
	}

	for i := start; i < len(nums); i++ {
		nums[i] = 0
	}
}

// 另一种解法
func moveZeroes(nums []int)  {
	j := 0
	for i := 0; i < len(nums); i++ {
		// != 0 的时候做交换
		if nums[i] != 0 {
			nums[j], nums[i] = nums[i], nums[j]
			j++
		}
	}
}