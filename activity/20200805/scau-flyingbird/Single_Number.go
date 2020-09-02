func singleNumber(nums []int) int {
	var res int
	for _, m := range nums {
		res ^= m
	}
	return res
}
