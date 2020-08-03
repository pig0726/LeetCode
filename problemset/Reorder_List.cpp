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
    ListNode* reverse(ListNode* head) {
        if (!head) return head;
        ListNode* pre = NULL;
        ListNode* p = head;
        ListNode* next = NULL;
        while (p) {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;    
        }

        fast = slow->next;
        slow->next = NULL;
        fast = reverse(fast);

        while (head && head->next) {
            ListNode* next = head->next;
            head->next = fast;
            head = next;

            next = fast->next;
            fast->next = head;
            fast = next;
        }

        head->next = fast;

        return;
    }
};
