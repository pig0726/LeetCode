class Solution {
public:
  int numSteps(string s) {
    int ret = 0;
    int n = s.length();
    int d = 0;
    for (int i = n-1; i >= 0; --i) {
      int val = s[i] - '0' + d;
      if (i == 0 && val == 1) break;

      if (val&1) {
        ++ret;
        ++val;
      }
      ++ret;
      d = val >> 1;
    }
    return ret;
  }
};
