import "math"

func minFallingPathSum(A [][]int) int {
	if len(A) == 0 {
		return 0
	}

	rows, cols := len(A), len(A[0])
	pos := []int{-1, 0, 1}
	var min int
	for i := 1; i < rows; i++ {
		for j := 0; j < cols; j++ {
			min = math.MaxInt32
			for k := 0; k < len(pos); k++ {
				if j+pos[k] >= 0 && j+pos[k] < cols {
					min = Min(min, A[i-1][j+pos[k]])
				}
			}
			A[i][j] = min + A[i][j]
		}
	}

	min = math.MaxInt32
	for i := 0; i < cols; i++ {
		min = Min(min, A[rows-1][i])
	}
	return min
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
