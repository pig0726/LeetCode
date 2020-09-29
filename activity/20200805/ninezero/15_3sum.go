func threeSum(nums []int) [][]int {
	// a + b = -c 排序加双指针
	var res [][]int
	if len(nums) < 3 {
		return res
	}
	sort.Ints(nums)
	// 从最小开始循环到==0结束
	for i := 0; i < len(nums) && nums[i] <= 0; i++ {
		// 避免重复
		if i >= 1 && nums[i] == nums[i-1] {
			continue
		}
		left, right := i+1, len(nums)-1
		for left < right {
			if nums[left] + nums[right] + nums[i] == 0 {
				res = append(res, []int{nums[i], nums[left], nums[right]})
				left += 1
				right -= 1
				// 去重
				for left < right && nums[left] == nums[left-1] {
					left++
				}
				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if nums[left] + nums[right] + nums[i] < 0 {
				left += 1
			} else {
				right -= 1
			}
		}
	}
	return res
}
