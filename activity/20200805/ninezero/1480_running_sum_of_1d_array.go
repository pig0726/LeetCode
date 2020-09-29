func runningSum(nums []int) []int {
	res := []int{}

	for i, value := range nums {
		if i == 0 {
			res = append(res, value)
		} else {
			res = append(res, res[i-1] + value)
		}
	}
	return res
}