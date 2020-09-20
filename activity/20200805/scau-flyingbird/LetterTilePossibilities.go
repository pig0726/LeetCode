func numTilePossibilities(tiles string) int {
	strs := []byte(tiles)
	cnt := make([]int, 26)
	for _, str := range strs {
		cnt[int(str-'A')]++
	}
	sum := 0
	backtrack(&cnt, &sum)
	return sum
}

func backtrack(cnt *[]int, sum *int) {
	for i := 0; i < 26; i++ {
		if (*cnt)[i] == 0 {
			continue
		}
		*sum++
		(*cnt)[i]--
		backtrack(cnt, sum)
		(*cnt)[i]++
	}
}


