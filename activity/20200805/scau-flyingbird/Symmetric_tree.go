/**
 * Definition for a binary tree node.
  * type TreeNode struct {
	   *     Val int
	    *     Left *TreeNode
	     *     Right *TreeNode
	      * }
*/

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	} else {
		return isSymmetricT(root.Left, root.Right)
	}
}

func isSymmetricT(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	} else if left == nil || right == nil {
		return false
	} else if left.Val != right.Val {
		return false
	} else {
		return isSymmetricT(left.Left, right.Right) && isSymmetricT(left.Right, right.Left)
	}

}
