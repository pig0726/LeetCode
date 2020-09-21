# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from functools import reduce

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        seq1 = self.get_leaf_value_seq(root1)
        seq2 = self.get_leaf_value_seq(root2)
        if len(seq1) != len(seq2):
            return False
        else:
            return reduce(lambda a, b: a and b, [x == y for x, y in zip(seq1, seq2)], True)
        
    def get_leaf_value_seq(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [root.val]
        else:
            return self.get_leaf_value_seq(root.left) \
                + self.get_leaf_value_seq(root.right)

