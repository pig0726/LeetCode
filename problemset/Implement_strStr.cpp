class Solution {
public:
    int strStr(string haystack, string needle) {
      int m = needle.length();
      if (!m) return 0;
      int n = haystack.length();
      for (int i = 0; i + m <= n; ++i) {
        if (!strncmp(haystack.c_str()+i, needle.c_str(), m))
          return i;
      }
      return -1;
    }
};
