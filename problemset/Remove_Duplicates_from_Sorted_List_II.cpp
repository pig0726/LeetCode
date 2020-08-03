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
        ListNode* ptr = head;
        ListNode* pre = NULL;
        head = NULL;
        while (ptr) {
            ListNode* next = ptr->next;
            if (next && ptr->val == next->val) {
                int dup = ptr->val;
                ListNode* pre2 = pre;
                ListNode* next2 = NULL;
                while (ptr && ptr->val == dup) {
                    next2 = ptr->next;
                    if (pre2) {
                        pre2->next = next2;
                    }
                    delete ptr;
                    ptr = next2;
                }
                if (pre) {
                    pre->next = ptr;
                }
            } else {
                if (!pre) head = ptr;
                pre = ptr;
                ptr = next;
            }
        }
        return head;
    }
};
