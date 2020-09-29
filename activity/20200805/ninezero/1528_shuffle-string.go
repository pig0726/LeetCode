func restoreString(s string, indices []int) string {
	temp := make([]byte, len(s))
	for idx, value := range indices {
		temp[value] = s[idx]
	}

	return string(temp)
}
