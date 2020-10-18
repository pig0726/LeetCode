/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var leaf1, leaf2 []int
	preOrder(root1, &leaf1)
	preOrder(root2, &leaf2)
	if !reflect.DeepEqual(leaf1, leaf2) {
		return false
	}
	return true
}

func preOrder(root *TreeNode, leaves *[]int) {
	if root == nil {
		return
	}

	if root.Left == nil && root.Right == nil {
		*leaves = append(*leaves, root.Val)
	}

	preOrder(root.Left, leaves)
	preOrder(root.Right, leaves)
}
