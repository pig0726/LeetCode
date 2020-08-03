class Solution {
public:
    inline static const int N = 1010;
    bool dp[N][N];
    int n, lidx, ridx;

    inline bool is_valid(int l, int r) {
      if (l > r) return true;
      return dp[l][r];
    }

    string longestPalindrome(string s) {
      n = s.length();
      memset(dp, 0, sizeof(dp));
      int ret = 0;
      for (int r = 0; r < n; ++r) {
        dp[r][r] = true;
        for (int l = 0; l < r; ++l)
          if (s[l] == s[r] && is_valid(l+1, r-1)) {
            dp[l][r] = true;
            if (r - l + 1 > ret) {
              ret = r - l + 1;
              lidx = l;
              ridx = r;
            }
          }
      }
      return s.substr(lidx, ridx-lidx+1);
    }
};
