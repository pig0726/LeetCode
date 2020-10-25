func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, n+1)
	}

	for k := 0; k < len(strs); k++ {
		sm, sn := findZeroOne(strs[k])
		for i := m; i >= sm; i-- {
			for j := n; j >= sn; j-- {
				dp[i][j] = Max(dp[i][j], dp[i-sm][j-sn]+1)
			}
		}
	}
	return dp[m][n]
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func findZeroOne(str string) (m int, n int) {
	s := []byte(str)
	for i := 0; i < len(s); i++ {
		if s[i] == '0' {
			m++
		} else if s[i] == '1' {
			n++
		}
	}
	return m, n
}
