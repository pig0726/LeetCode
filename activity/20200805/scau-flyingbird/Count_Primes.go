func countPrimes(n int) int {
	if n < 3 {
		return 0
	}
	cnt := 0
	isPrime := make([]bool, n)
	for i := 2; i < n; i++ {
		if !isPrime[i] {
			cnt++
			for j := 2; j*i < n; j++ {
				isPrime[j*i] = true
			}
		}
	}
	return cnt
}
