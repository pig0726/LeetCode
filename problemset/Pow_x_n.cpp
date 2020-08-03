class Solution {
public:
    double pow(double x, long long n) {
      if (n == 0) return 1;
      else if (n == 1) return x;
      double ret = pow(x, n>>1);
      ret *= ret;
      if (n&1) ret *= x;
      return ret;
    }
    double myPow(double x, int n) {
      long long absn = abs(1LL * n);
      double ret = pow(x, absn);
      if (n < 0) return 1. / ret;
      return ret;
    }
};
