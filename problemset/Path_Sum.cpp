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
    bool dfs(TreeNode* root, int sum, int target) {
        int cnt = 0;
        if (root->left) {
            cnt++;
            if (dfs(root->left, sum + root->left->val, target)) {
                return true;
            }
        }
        if (root->right) {
            cnt++;
            if (dfs(root->right, sum + root->right->val, target)) {
                return true;
            }
        }
        if (cnt == 0) {
            if (sum == target) return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return dfs(root, root->val, sum);
    }
};
