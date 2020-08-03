class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> stk;
      int n = s.length();
      int ret = 0;
      stk.push(-1);
      for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '(') stk.push(i);
        else {
          
          int tid = stk.top();
          if (tid == -1 || s[tid] == ')') {
            stk.push(i);
            continue;
          }
          stk.pop();
          ret = max(ret, i-stk.top());
        }
      }
      return ret;
    }
};
