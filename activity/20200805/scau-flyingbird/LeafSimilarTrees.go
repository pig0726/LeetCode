/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	r1 := make([]int, 0)
	r2 := make([]int, 0)
	searchLeaf(root1, &r1)
	searchLeaf(root2, &r2)
	return checkIsSimilar(r1, r2)
}

func searchLeaf(root *TreeNode, m *[]int) {
	if root == nil {
		return
	} else if root.Left == nil && root.Right == nil {
		*m = append(*m, root.Val)
	} else {
		searchLeaf(root.Left, m)
		searchLeaf(root.Right, m)
	}
}

func checkIsSimilar(r1 []int, r2 []int) bool {
	if len(r1) != len(r2) {
		return false
	}
	for i, v := range r1 {
		if r2[i] != v {
			return false
		}
	}
	return true
}
