class Solution {
public:
    string longestPrefix(string s) {
      int n = s.length();
      vector<int> next(n+1);
      int i = 0, j = -1;
      next[0] = -1;
      while (i < n) {
        if (j == -1 || s[i] == s[j]) {
          ++i;
          ++j;
          next[i] = j;
        } else j = next[j];
      }
      return s.substr(0, next[n]);
    }
};
