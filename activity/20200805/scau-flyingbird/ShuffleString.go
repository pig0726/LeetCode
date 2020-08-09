func restoreString(s string, indices []int) string {
	res, tmp := []byte(s), []byte(s)
	for i := 0; i < len(indices); i++ {
		res[indices[i]] = tmp[i]
	}
	return string(res)
}


