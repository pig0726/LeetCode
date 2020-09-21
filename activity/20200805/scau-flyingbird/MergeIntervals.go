import "sort"

type ints [][]int

func (s ints) Len() int {
	return len(s)
}

func (s ints) Less(i int, j int) bool {
	return s[i][0] < s[j][0]
}

func (s ints) Swap(i int, j int) {
	s[i], s[j] = s[j], s[i]
}

func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return intervals
	}

	sort.Sort(ints(intervals))

	i, j := 1, 0
	for ; i < len(intervals); i++ {
		if intervals[j][0] <= intervals[i][0] && intervals[i][0] <= intervals[j][1] {
			//in
			intervals[j][1] = max(intervals[i][1], intervals[j][1])
		} else {
			j++
			intervals[j][0] = intervals[i][0]
			intervals[j][1] = intervals[i][1]
		}
	}
	return intervals[:(j + 1)]
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

