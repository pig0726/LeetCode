func sortedSquares(A []int) []int {
	l, r, idx, res := 0, len(A)-1, len(A)-1, make([]int, len(A))
	for l <= r {
		sql := A[l] * A[l]
		sqr := A[r] * A[r]
		if sqr >= sql {
			res[idx] = sqr
			r--
		} else {
			res[idx] = sql
			l++
		}
		idx--
	}
	return res
}
