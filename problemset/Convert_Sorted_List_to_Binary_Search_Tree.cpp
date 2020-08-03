/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* dfs(ListNode* st, ListNode* ed) {
        if (st == ed) return NULL;
        ListNode* fast = st;
        ListNode* slow = st;
        while (fast->next != ed && fast->next->next != ed) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        TreeNode* left = dfs(st, slow);
        TreeNode* right = dfs(slow->next, ed);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return dfs(head, NULL);
    }
};
