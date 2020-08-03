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
    void dfs(TreeNode* rt, int depth, int& ret) {
        depth++;
        int cnt = 0;
        if (rt->left) {
            dfs(rt->left, depth, ret);
            cnt++;
        }
        if (rt->right) {
            dfs(rt->right, depth, ret);
            cnt++;
        }
        if (!cnt) {
            ret = min(ret, depth);
        }
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ret = INT_MAX;
        dfs(root, 0, ret);
        return ret;
    }
};
