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
    TreeNode* dfs(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* taill = dfs(root->left);
        TreeNode* tailr = dfs(root->right);
        if (taill) {
            taill->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (tailr) return tailr;
        else if (taill) return taill;
        else return root;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
