func removeDuplicates(nums []int) int {
	i, j, l := 0, 1, len(nums)
	if l < 2 {
		return l
	} else {
		for j < l {
			if nums[i] != nums[j] {
				i++
				nums[i] = nums[j]
			}
			j++
		}
		return i + 1
	}
}
