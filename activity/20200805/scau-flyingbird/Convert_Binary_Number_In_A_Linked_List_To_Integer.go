func getDecimalValue(head *ListNode) int {
	num := 0
	for head != nil {
		num = num<<1 + head.Val
		head = head.Next
	}
	return num
}
