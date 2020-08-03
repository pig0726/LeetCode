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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        if (!h2) return h1;
        if (!h1) return h2;
        ListNode* head = NULL;
        ListNode* ptr = NULL;
        if (h1->val <= h2->val) {
            ptr = head = h1;
            h1 = h1->next;
            ptr->next = NULL;
        }
        else {
            ptr = head = h2;
            h2 = h2->next;
            ptr->next = NULL;
        }

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                ptr->next = h1;
                ptr = h1;
                h1 = h1->next;
                ptr->next = NULL;
            } else {
                ptr->next = h2;
                ptr = h2;
                h2 = h2->next;
                ptr->next = NULL;
            }
        }
        while (h1) { ptr->next = h1; ptr = h1; h1 = h1->next; }
        while (h2) { ptr->next = h2; ptr = h2; h2 = h2->next; }
        return head;
    }

    ListNode* sort(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = NULL;

        ListNode* h1 = sort(head);
        ListNode* h2 = sort(tmp);

        return merge(h1, h2);

    }

    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};
