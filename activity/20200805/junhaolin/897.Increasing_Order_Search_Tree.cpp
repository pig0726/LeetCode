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
    TreeNode* increasingBST(TreeNode* root) {
        if (NULL == root)   
            return root;
        
        if (root->right)
            root->right = increasingBST(root->right);
        
        if (root->left)     {
            TreeNode* newRoot = increasingBST(root->left);
            TreeNode *rightmost = findRightMost(newRoot);
            rightmost->right = root;
            root->left = NULL;
            return newRoot;
        }
        
        return root;
    }
    
    TreeNode* findRightMost(TreeNode* root) {
        if (root->right)
            return findRightMost(root->right);
        else
            return root;
    }
   
};
