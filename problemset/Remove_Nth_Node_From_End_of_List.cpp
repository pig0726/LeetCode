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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (!head) return nullptr;
      int tot = 0;
      ListNode* now = head;
      while (now) {
        ++tot;
        now = now->next;
      }
      n = tot - n;
      ListNode* pre = nullptr;
      now = head;
      for (int i = 0; i < n; ++i) {
        pre = now;
        now = now->next;
      }
      if (pre) pre->next = now->next;
      else head = now->next;
      return head;
    }
};

