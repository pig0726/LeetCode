func removeDuplicates(nums []int) int {
	p, q := 0, 1
	for q < len(nums) {
		if nums[p] != nums[q] {
			if p + 1 < q {
				nums[p+1] = nums[q]
			}
			p++
		}
		q++
	}
	return p+1
}
