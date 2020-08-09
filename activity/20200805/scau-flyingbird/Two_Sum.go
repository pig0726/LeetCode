func twoSum(nums []int, target int) []int {
	length := len(nums)
	m := make(map[int]int, length)
	for i := 0; i < length; i++ {
		if x, ok := m[target-nums[i]]; ok {
			return []int{x, i}
		} else {
			m[nums[i]] = i
		}
	}
	return []int{}
}

