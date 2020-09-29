func subtractProductAndSum(n int) int {
	product, sum := 1, 0
	length := len(strconv.Itoa(n))
	for i := 0; i < length; i++ {
		product *= n % 10
		sum += n % 10
		n /= 10
	}
	return product - sum
}
