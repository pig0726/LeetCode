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
    TreeNode* dfs(int start, int end, vector<int>& nums) {
        if (end < start) return NULL;
        int mid = ((end - start + 1) >> 1) + start;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = dfs(start, mid-1, nums);
        TreeNode* right = dfs(mid+1, end, nums);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};
