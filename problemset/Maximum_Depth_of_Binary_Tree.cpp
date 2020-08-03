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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        dfs(root, 0, maxDepth);
        return maxDepth;
    }
private:
    void dfs(TreeNode* root, int depth, int& maxDepth) {
        if (!root) {
            return;
        }
        ++depth;
        maxDepth = depth > maxDepth ? depth : maxDepth;
        dfs(root->left, depth, maxDepth);
        dfs(root->right, depth, maxDepth);
    }
};
