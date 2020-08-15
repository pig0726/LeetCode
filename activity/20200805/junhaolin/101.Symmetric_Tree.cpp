/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (NULL == root)   
            return true;
        else                
            return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (NULL == left && NULL == right)  
            return true;
        else if (NULL != left && NULL != right && left->val == right->val)
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        else
            return false;
    }
};
