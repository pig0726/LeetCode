# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        ans = self.cur = TreeNode()
        self.relink(root)
        return ans.right
        
    def relink(self, node: TreeNode) -> None:
        if node:
            self.relink(node.left)
            self.cur.left = None
            self.cur.right = node
            self.cur = node
            self.relink(node.right)

