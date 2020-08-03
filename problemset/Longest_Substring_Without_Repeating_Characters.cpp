class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ret = 0;
      int n = s.length();
      int map[300];
      memset(map, -1, sizeof(map));
      int l = 0, r = 0;
      while (r < n) {
        int pos = map[s[r]];
        if (l <= pos && pos < r) l = pos + 1;
        ret = max(r - l + 1, ret);
        map[s[r]] = r;
        ++r;
      }
      return ret;
    }
};

