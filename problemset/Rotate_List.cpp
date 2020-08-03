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
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head) return nullptr;
      int n = 0;
      ListNode* now = head;
      ListNode* last = head;
      while (now) {
        ++n;
        now = now->next;
        if (now) last = now;
      }
      k %= n;
      if (!k) return head;
      int re = n - k;
      now = head;
      for (int i = 0; i < re-1; ++i) {
        now = now->next;
      }
      ListNode* new_head = now->next;
      now->next = nullptr;
      last->next = head;
      return new_head;
    }
};
