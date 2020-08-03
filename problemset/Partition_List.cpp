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
    ListNode* partition(ListNode* head, int x) {
        ListNode* insert = NULL;
        ListNode* ptr = head;
        ListNode* pre = NULL;
        while (ptr) {
            if (ptr->val < x) {
                ListNode* next = ptr->next;

                if (ptr == head) {
                    insert = head;
                    pre = ptr;
                    ptr = next;
                    continue;
                }

                if (!insert) {
                    pre->next = next;
                    ptr->next = head;
                    insert = ptr;
                    head = ptr;
                    ptr = next;
                    continue;
                }

                if (insert && insert->next == ptr) {
                    pre = ptr;
                    insert = ptr;
                    ptr = next;
                    continue;
                }

                pre->next = next;
                ListNode* inext = insert->next;
                ptr->next = inext;
                insert->next = ptr;
                insert = ptr;
                ptr = next;

            } else {
                pre = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};
