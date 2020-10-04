func nextGreatestLetter(letters []byte, target byte) byte {
	if letters[len(letters)-1] <= target {
		return letters[0]
	}
	left, right := 0, len(letters)-1
	for left + 1 < right {
		mid := (left + right) / 2
		if letters[mid] < target {
			left = mid
		} else if letters[mid] > target {
			right = mid
		} else {
			left = mid
		}
	}

	if letters[left] > target {
		return letters[left]
	}
	return letters[right]
}