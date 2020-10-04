func selfDividingNumbers(left int, right int) []int {
	var res []int
	for i := left; i <= right; i++ {
		if isSelfDividingNumber(i) {
			res = append(res, i)
		}
	}
	return res
}

func isSelfDividingNumber(num int) bool {
	length := len(strconv.Itoa(num))
	temp := num
	for i := 0; i < length; i++ {
		// 每一位数
		n := num % 10
		if n == 0 || (n != 0 && temp % n != 0) {
			return false
		}
		num /= 10
	}
	return true
}

