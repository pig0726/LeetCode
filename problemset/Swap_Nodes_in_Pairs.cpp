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
    ListNode* swapPairs(ListNode* head) {
      ListNode* ret = nullptr;
      ListNode* pre = nullptr;
      ListNode* ptr[3]{nullptr, nullptr, nullptr};
      while (true) {
        if (pre) ptr[0] = pre->next;
        else ptr[0] = head;

        if (!ptr[0]) break;

        ptr[1] = ptr[0]->next;
        if (ptr[1]) ptr[2] = ptr[1]->next;
        else ptr[2] = nullptr;

        if (!ptr[1]) {
          if (!ret) ret = ptr[0];
          break;
        }

        ptr[0]->next = ptr[2];
        ptr[1]->next = ptr[0];
        if (!pre) {
          ret = ptr[1];
        } else {
          pre->next = ptr[1];
        }

        pre = ptr[0];
      }
      return ret;
    }
};

