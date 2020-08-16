func moveZeroes(nums []int) {
	idx := 0
	for i, num := range nums {
		if num != 0 {
			nums[idx] = nums[i]
			idx++
		}
	}
	for i := idx; i < len(nums); i++ {
		nums[i] = 0
	}
}
