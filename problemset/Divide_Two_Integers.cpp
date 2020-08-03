class Solution {
public:
    int divide(int dividend, int divisor) {
      using LL = long long;
      LL sign = 1LL;
      LL a = dividend;
      LL b = divisor;
      LL absb = abs(1LL * divisor);
      
      if (a < 0LL) {
        sign *= -1LL;
        a *= -1LL;
      }
      
      if (b < 0LL) {
        sign *= -1LL;
        b *= -1LL;
      }
      
      LL cnt = 1LL;
      while (b < a) {
        b <<= 1;
        cnt <<= 1;
      }
      
      LL ret = 0LL;
      while (a && b >= absb) {
        if (a >= b) {
          ret += cnt;
          a -= b;
        }
        b >>= 1LL;
        cnt >>= 1LL;
      }
      ret *= sign;
      if (ret > INT_MAX) ret = INT_MAX;
      else if (ret < INT_MIN) ret = INT_MIN;
      return ret;
    }
};
