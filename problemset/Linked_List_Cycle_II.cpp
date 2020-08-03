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
    ListNode* find(ListNode* p1, ListNode* p2) {
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) p2 = p2->next;
            if (p1 == p2) break;
        }

        if (!p1 || !p2) return NULL;
        return p1;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* p = find(head, head);
        if (!p) return NULL;
        while (true) {
            if (head == p) return p;
            head = head->next;
            p = p->next;
        }
        return NULL;
    }
};
