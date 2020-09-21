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
    void dfs(TreeNode* root, vector<int>& ret) {
        if (!root) return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1, ret2;
        dfs(root1, ret1);
        dfs(root2, ret2);
        vector<int> ret;
        int p[2]{0, 0};
        while (p[0] < ret1.size() && p[1] < ret2.size()) {
            if (ret1[p[0]] <= ret2[p[1]]) {
                ret.push_back(ret1[p[0]++]);
            } else {
                ret.push_back(ret2[p[1]++]);
            }
        }
        while (p[0] < ret1.size())
            ret.push_back(ret1[p[0]++]);
        while (p[1] < ret2.size())
            ret.push_back(ret2[p[1]++]);
        return ret;
    }
};