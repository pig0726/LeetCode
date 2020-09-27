func checkSubarraySum(nums []int, k int) bool {
	mod, subSum := map[int]int{0: -1}, 0
	for i, num := range nums {
		subSum += num
		if k != 0 {
			subSum %= k
		}
		idx, ok := mod[subSum]
		if !ok {
			//first mod
			mod[subSum] = i
		} else {
			if i-idx > 1 {
				return true
			}
		}
	}
	return false
}
