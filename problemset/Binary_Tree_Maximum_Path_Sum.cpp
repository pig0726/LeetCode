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
    int dfs(TreeNode* root, int& ret) {
        if (!root) return 0;
        int dpl = dfs(root->left, ret);
        if (dpl < 0) dpl = 0;
        int dpr = dfs(root->right, ret);
        if (dpr < 0) dpr = 0;
        ret = max(ret, dpl + dpr + root->val);
        return max(dpl, dpr) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};
