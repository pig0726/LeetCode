class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int n = strs.size();
      if (!n) return "";
      int m = strs[0].length();
      int idx = 0;
      for (idx = 0; idx < m; ++idx) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
          if (idx >= strs[i].length() || strs[i][idx] != strs[0][idx]) {
            flag = false;
            break;
          }
        }
        if (!flag) break;
      }
      if (!idx) return "";
      return strs[0].substr(0, idx);
    }
};
