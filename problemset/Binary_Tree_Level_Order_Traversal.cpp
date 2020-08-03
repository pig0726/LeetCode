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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        vector<TreeNode*>* p1;
        vector<TreeNode*>* p2;
        p1 = &v1;
        p2 = &v2;
        p1->push_back(root);
        while (!p1->empty()) {
            p2->clear();
            vector<int> _ret;
            int size = p1->size();
            for (int i = 0; i < size; i++) {
                TreeNode* tn = (*p1)[i];
                _ret.push_back(tn->val);
                if (tn->left) p2->push_back(tn->left);
                if (tn->right) p2->push_back(tn->right);
            }
            ret.push_back(_ret);
            swap(p1, p2);
        }
        return ret;
    }
};
