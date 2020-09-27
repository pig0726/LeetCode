func isSelfDividing(num int) bool {
	tmp := num
	for tmp != 0 {
		m := tmp % 10
		if m == 0 {
			return false
		}
		if num%m != 0 {
			return false
		}
		tmp /= 10
	}
	return tmp == 0
}

func selfDividingNumbers(left int, right int) []int {
	num := []int{}
	for i := left; i <= right; i++ {
		if isSelfDividing(i) {
			num = append(num, i)
		}
	}
	return num
}
