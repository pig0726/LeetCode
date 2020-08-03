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
    void dfs(TreeNode* root, int& ans, int& ret) {
        if (!root) return;
        ans = ans * 10 + root->val;
        if (!root->left && !root->right) {
            ret += ans;
            ans = (ans - root->val) / 10;
            return;
        }
        if (root->left) {
            dfs(root->left, ans, ret);
        }
        if (root->right) {
            dfs(root->right, ans, ret);
        }
        ans = (ans - root->val) / 10;
    }

    int sumNumbers(TreeNode* root) {
        int ret = 0;
        int s = 0;
        dfs(root, s, ret);
        return ret;
    }
};
