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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        leaf(root1, v1);
        leaf(root2, v2);
        return v1 == v2;
    }
    
    void leaf(TreeNode * root, vector<int>& v) {
        if (NULL == root)       return;
        
        if (root->left)         leaf(root->left, v);
        if (root->right)        leaf(root->right, v);
        
        if (NULL == root->left && NULL == root->right)
            v.push_back(root->val);
    }
};
