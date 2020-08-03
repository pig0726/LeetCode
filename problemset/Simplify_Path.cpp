class Solution {
public:
    string simplifyPath(string path) {
      int n = path.length();
      if (!n) return "";
      vector<string> stk;
      for (int i = 0, j = 0; i < n; i = j) {
        assert(path[i] == '/');
        j = i+1;
        while (j < n && path[j] != '/') ++j;
        int len = j - 1 - i;
        if (len == 0 || (len == 1 && path[i+1] == '.')) {
          continue;
        } else if (len == 2 && path[i+1] == '.' && path[i+2] == '.') {
          if (stk.size()) stk.pop_back();
          continue;
        } else {
          string block = path.substr(i+1, len);
          stk.push_back(block);
        }
      }
      string ret("/");
      for (int i = 0; i < stk.size(); ++i) {
        ret += stk[i];
        if (i != stk.size()-1) ret += "/";
      }
      return ret;
    }
};
