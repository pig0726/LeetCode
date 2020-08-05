/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var increasingBST = function(root) {
    var prenode = null, first = null;
    var dfs = function(node) {
        if (!node) return;
        
        dfs(node.left);
        if (!first) first = node;
        node.left = null;
        if (prenode != null) {
            prenode.right = node;
        }
        prenode = node;
        dfs(node.right);
    }
    dfs(root);
    return first;
};
