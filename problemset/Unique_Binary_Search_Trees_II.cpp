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
    vector<TreeNode*> dfs(int* vis, int low, int high) {
        vector<TreeNode*> ret;

        if (high <= low) {
            return ret;
        }

        for (int i = low; i < high; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            vector<TreeNode*> lsons = dfs(vis, low, i);
            vector<TreeNode*> rsons=  dfs(vis, i+1, high);
            if (lsons.empty()) lsons.push_back(NULL);
            if (rsons.empty()) rsons.push_back(NULL);
            for (int l = 0; l < lsons.size(); l++) {
                for (int r = 0; r < rsons.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lsons[l];
                    root->right = rsons[r];
                    ret.push_back(root);
                }
            }
            vis[i] = 0;
        }

        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        int* vis = new int[n+1];
        memset(vis, 0, sizeof(int) * (n+1));
        return dfs(vis, 1, n+1);
    }
};
