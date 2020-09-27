func hammingWeight(num uint32) int {
	n := 0
	for num != 0 {
		num &= (num - 1)
		n++
	}
	return n
}
