// 暴力解法timeout 无法通过
func countPrimes(n int) int {
	res := 0
	for i := 1; i < n; i++ {
		if isPrime(i) {
			res++
		}
	}
	return res
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n % i == 0 {
			return false
		}
	}
	return true
}

// 另一种解法
func countPrimes(n int) int {
	count := 0
	notPrimes := make([]bool, n)
	// 0 和 1都不是质数
	for i := 0; i < n; i++ {
		if i > 1 {
			break
		}
		notPrimes[i] = true
	}
	for i := 2; i * i < n; i++ {
		for j := i*i; j < n; j += i {
			notPrimes[j] = true
		}
	}
	for i := 0; i < n; i++ {
		if !notPrimes[i] {
			count++
		}
	}
	return count
}
