func sortedSquares(A []int) []int {
	// 双指针
	res := make([]int, len(A))
	left, right, k := 0, len(A)-1, len(A)-1
	for k >= 0 {
		if math.Abs(float64(A[left])) < math.Abs(float64(A[right])) {
			res[k] = A[right] * A[right]
			right--
		} else {
			res[k] = A[left] * A[left]
			left++
		}
		k--
	}
	return res
}