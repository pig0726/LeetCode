import "math"

func mincostTickets(days []int, costs []int) int {
	idx := []int{1, 7, 30}
	sum := make([]int, len(days))
	for i := 0; i < len(days); i++ {
		sum[i] = math.MaxInt32
	}
	return cal(0, &sum, &days, &costs, &idx)
}

func cal(i int, sum *[]int, days *[]int, costs *[]int, idx *[]int) int {
	if i >= len(*days) {
		return 0
	}

	if (*sum)[i] != math.MaxInt32 {
		return (*sum)[i]
	}

	min := math.MaxInt32
	for k := 0; k < len(*idx); k++ {
		j := i + 1
		for ; j < len(*days) && (*days)[j] < (*days)[i]+(*idx)[k]; j++ {

		}
		min = Min(min, cal(j, sum, days, costs, idx)+(*costs)[k])
	}
	(*sum)[i] = min
	return (*sum)[i]
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
