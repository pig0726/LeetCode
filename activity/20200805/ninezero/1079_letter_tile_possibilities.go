func numTilePossibilities(tiles string) int {
	// 统计每一个字母的出现个数
	letters := make([]int, 26)
	for i := 0; i < len(tiles); i++ {
		letters[tiles[i]-'A'] += 1
	}
	return dfs(letters)
}

func dfs(letters []int) int {
	count := 0
	for i, value := range letters {
		if value == 0 {
			continue
		}
		count++
		letters[i]--
		count += dfs(letters)
		letters[i]++
	}
	return count
}
