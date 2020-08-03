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
    int ret = 0;
    vector<int> cnt;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        int scnt = 0;
        cnt[root->val]++;
        if (root->left) {
            scnt++;
            dfs(root->left);
        }
        if (root->right) {
            scnt++;
            dfs(root->right);
        }
        if (!scnt) {
            int odd = 0;
            for (int i = 0; i < 10; ++i)
                if (cnt[i] & 1) odd++;
            if (odd <= 1) ret++;
        }
        cnt[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ret = 0;
        cnt.assign(10, 0);
        dfs(root);
        return ret;
    }
};
