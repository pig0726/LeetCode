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
    void dfs(TreeNode* root, int sum, int target, vector<int>& path, vector<vector<int> >& ret) {
        int cnt = 0;
        sum += root->val;
        path.push_back(root->val);

        if (root->left) {
            cnt++;
            dfs(root->left, sum, target, path, ret);
        }
        if (root->right) {
            cnt++;
            dfs(root->right, sum, target, path, ret);
        }
        if (cnt == 0) {
            if (sum == target) {
                ret.push_back(path);
            }
        }
        path.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> path;
        if (!root) return ret;
        dfs(root, 0, sum, path, ret);
        return ret;
    }
};
