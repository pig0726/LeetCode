//gcf为n的最大公因数,则
//minSteps(n) = minSteps(gcf) + 1 + (n/gcf - 1) n >= 2
//minSteps(n) = 0 n == 1
//即先组合最大公因数 + 1次C + (n/gcf - 1)次P
func minSteps(n int) int {
	if n == 1 {
		return 0
	}
	gcf := getGCF(n)
	return minSteps(gcf) + 1 + (n/gcf - 1)
}

//计算n的最大公因数(greatest common factor)
func getGCF(n int) int {
	max := 1
	for i := 2; i < n/2; i++ {
		if n%i == 0 {
			max = n / i
			break
		}
	}
	return max
}










