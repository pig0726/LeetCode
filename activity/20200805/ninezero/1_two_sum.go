func twoSum(nums []int, target int) []int {
	res := []int{}
	hash := make(map[int]int)

	for i, value := range nums {
		if index, ok := hash[target-value]; ok {
			res = append(res, index)
			res = append(res, i)
			return res
		} else {
			hash[value] = i
		}
	}

	return res
}