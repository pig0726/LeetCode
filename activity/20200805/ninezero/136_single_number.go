func singleNumber(nums []int) int {
	var res int
	for _, value := range nums {
		res = res ^ value
	}
	return res
}