func isSubsequence(s string, t string) bool {
	n := len(s)
	pos := 0
	for i := 0; i < len(t) && pos < n; i++ {
		if t[i] == s[pos] {
			pos++
		}
	}
	return pos == n
}
