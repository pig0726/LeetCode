/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func increasingBST(root *TreeNode) *TreeNode {
	var treeValues []int
	bst(root, &treeValues)
	treeNode := &TreeNode{Val: treeValues[0]}
	currentNode := treeNode
	for i := 1; i < len(treeValues); i++ {
		currentNode.Right = &TreeNode{Val: treeValues[i]}
		currentNode = currentNode.Right
	}
	return treeNode
}

func bst(node *TreeNode, treeValues *[]int) {
	if node.Left != nil {
		bst(node.Left, treeValues)
	}
	*treeValues = append(*treeValues, node.Val)
	if node.Right != nil {
		bst(node.Right, treeValues)
	}
}


