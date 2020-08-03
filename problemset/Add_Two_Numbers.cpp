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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ptr[2] = {l1, l2};
      int value[2] = {0, 0};
      int c = 0;

      ListNode* head = nullptr;
      ListNode* now = nullptr;

      while (ptr[0] || ptr[1] || c) {
        for (int i = 0; i < 2; ++i)
          value[i] = ptr[i] ? ptr[i]->val : 0;
        int sum = value[0] + value[1] + c;
        int v = sum % 10;
        c = sum / 10;

        ListNode* cur = new ListNode(v);
        if (!head) {
          head = now = cur;
        } else {
          now->next = cur;
          now = cur;
        }

        for (int i = 0; i < 2; ++i)
          if (ptr[i]) ptr[i] = ptr[i]->next;
      }

      return head;
    }
};
