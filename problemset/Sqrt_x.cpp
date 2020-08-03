class Solution {
public:
    int mySqrt(int x) {
      if (x == 0) return 0;
      if (x == 1) return 1;
      using LL = long long;
      int low = 1, high = x>>1, ans = -1;
      while (low <= high) {
        LL mid = (1LL * (low + high)) >> 1LL;
        if (mid * mid <= 1LL * x) {
          ans = mid;
          low = mid + 1;
        } else high = mid - 1;
      } 
      return ans;
    }
};
