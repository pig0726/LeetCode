/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* ptr = head;
        while (ptr) {
            if (ptr == head || ptr->val != pre->val) {
                pre = ptr;
                ptr = ptr->next;
            } else {
                ListNode* next = ptr->next;
                pre->next = next;
                delete ptr;
                ptr = next;
            }
        }
        return head;
    }
};
