class Solution {
public:
    bool isValid(string s) {
      std::stack<char> stk;
      for (auto& x : s) {
        if (x == '(' || x == '[' || x == '{') stk.push(x);
        else {
          if (stk.empty()) return false;
          char c = stk.top();
          stk.pop();
          switch (x) {
            case ')':
              if (c != '(') return false;
              break;
            case ']':
              if (c != '[') return false;
              break;
            case '}':
              if (c != '{') return false;
              break;
            default:
              return false;
          }
        }
      }
      return stk.empty();
    }
};
