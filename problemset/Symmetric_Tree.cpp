/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* lroot, TreeNode* rroot) {
        if (!lroot && !rroot) return true;
        if (!lroot | !rroot) return false;
        if (lroot->val != rroot->val) return false;
        bool ret = dfs(lroot->left, rroot->right);
        if (!ret) return false;
        ret = dfs(lroot->right, rroot->left);
        if (!ret) return false;
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
};
