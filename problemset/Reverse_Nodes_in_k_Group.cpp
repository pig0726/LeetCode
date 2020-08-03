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
    ListNode* reverse(ListNode* st, ListNode* ed) {
        ListNode* pre = NULL;
        ListNode* p = st;
        ListNode* next = p->next;
        while (p != ed) {
            st = p;
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return st;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            for (int i = 0; i < k; i++) {
                if (!fast) return head;
                fast = fast->next;
            }
            ListNode* new_head = reverse(slow, fast);
            if (!pre) {
                head = new_head;
            } else {
                pre->next = new_head;
            }
            slow->next = fast;
            pre = slow;
            slow = fast;
        }

        return head;
    }
};
