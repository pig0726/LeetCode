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
    ListNode* reverseKGroup(ListNode* head, int k) {
      stack<ListNode*> stk;
      ListNode* ret = nullptr;
      ListNode* pre = nullptr;
      ListNode* now = nullptr;
      
      while (true) {
        bool flag = true;
        if (pre) now = pre->next;
        else now = head;
        for (int i = 0; i < k; ++i) {
          if (!now) {
            flag = false;
            break;
          }
          stk.push(now);
          now = now->next;
        }
        if (!flag) {
          if (!ret) ret = head;
          break;
        }
        
        ListNode* nxt = now;
        
        while (!stk.empty()) {
          ListNode* top = stk.top();
          stk.pop();
          if (!pre) {
            ret = top;
          } else {
            pre->next = top;
          }
          pre = top;
        }
        pre->next = nxt;
      }
      return ret;
    }
};
