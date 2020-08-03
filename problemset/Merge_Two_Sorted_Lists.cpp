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
    void update(ListNode** ptr, ListNode** head, ListNode** now) {
      if (!(*head)) *head = *ptr;
      if (*now) (*now)->next = *ptr;
      *now = *ptr;
      *ptr = (*ptr)->next;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* head = nullptr;
      ListNode* now = nullptr;

      while (l1 || l2) {
        if (!l1) update(&l2, &head, &now);
        else if (!l2) update(&l1, &head, &now);
        else if (l1->val < l2->val) update(&l1, &head, &now);
        else update(&l2, &head, &now);
      }

      return head;
    }
};
