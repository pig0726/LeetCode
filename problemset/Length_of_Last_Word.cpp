class Solution {
public:
    int lengthOfLastWord(string s) {
      int ret = 0;
      int L = -1, R = -1;
      for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
          R = i;
          if (L == -1) L = i;
        } else {
          if (L != -1) ret = R - L + 1;
          L = R = -1;
        }
      }
      if (L != -1) ret = R - L + 1;
      return ret;
    }
};
