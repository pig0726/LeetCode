func subtractProductAndSum(n int) int {
	sum, plus, m := 0, 1, 0
	for n != 0 {
		m = n % 10
		n = n / 10
		sum += m
		plus = plus * m
	}
	return plus - sum
}
