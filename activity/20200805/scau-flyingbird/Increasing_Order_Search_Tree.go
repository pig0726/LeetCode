/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func walk(root *TreeNode, ch chan int) {
	if root == nil {
		return
	}

	walk(root.Left, ch)
	ch <- root.Val
	walk(root.Right, ch)
}

func increasingBST(root *TreeNode) *TreeNode {
	ch := make(chan int)
	go func() {
		defer close(ch)
		walk(root, ch)
	}()

	ordered := &TreeNode{}
	head := ordered
	for c := range ch {
		t := &TreeNode{c, nil, nil}
		ordered.Right = t
		ordered = ordered.Right
	}
	return head
}
