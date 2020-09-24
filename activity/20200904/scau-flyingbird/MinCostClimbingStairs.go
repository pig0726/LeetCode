func minCostClimbingStairs(cost []int) int {
	l := len(cost)
	if l == 0 {
		return 0
	} else if l == 1 {
		return cost[0]
	}
	step1, step2 := cost[0], cost[1]
	for i := 2; i < l; i++ {
		next := Min(step1, step2) + cost[i]
		step1 = step2
		step2 = next
	}
	return Min(step1, step2)
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
