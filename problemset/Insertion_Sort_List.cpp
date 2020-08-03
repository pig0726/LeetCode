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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* nptr = NULL;
        head = NULL;
        while (ptr) {
            nptr = ptr->next;
            ptr->next = head;
            head = ptr;
            while (ptr->next && ptr->val > ptr->next->val) {
                swap(ptr->val, ptr->next->val);
                ptr = ptr->next;
            }
            ptr = nptr;
        }
        return head;
    }
};
