func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	min, max := prices[0], 0
	for i := 1; i < len(prices); i++ {
		max = Max(max, prices[i]-min)
		min = Min(min, prices[i])
	}
	return max
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
