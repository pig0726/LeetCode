# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.isSymmetricTrees(root.left, root.right)
        
    def isSymmetricTrees(self, p: TreeNode, q: TreeNode) -> bool:
        """
        detect whether p and q are symmetirc
        """
        if p and q:
            return p.val == q.val and self.isSymmetricTrees(p.left, q.right) \
                and self.isSymmetricTrees(p.right, q.left)
        return p is q

