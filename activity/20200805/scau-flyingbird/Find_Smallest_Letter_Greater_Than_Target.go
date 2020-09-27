func nextGreatestLetter(letters []byte, target byte) byte {
	length := len(letters)
	left, right := 0, length-1
	for left <= right {
		mid := left + (right-left)/2
		if letters[mid] <= target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return letters[left%length]
}
