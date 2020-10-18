func merge(intervals [][]int) [][]int {
	// 排序
	sort.Sort(Section(intervals))
	res := make([][]int, len(intervals))
	idx := -1
	// 遍历intervals
	for i := 0; i < len(intervals); i++ {
		if idx == -1 || res[idx][1] < intervals[i][0] {
			idx++
			res[idx] = intervals[i]
		} else {
			res[idx][1] = int(math.Max(float64(res[idx][1]), float64(intervals[i][1])))
		}
	}

	return res[:idx+1]
}

type Section [][]int

func (s Section) Len() int {
	return len(s)
}

func (s Section) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s Section) Less(i, j int) bool {
	return s[i][0] < s[j][0]
}
