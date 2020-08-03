class Solution {
public:
    int reverse(int x) {
      std::string str = std::to_string(x);
      using ll = long long;
      ll ret = 0;
      for (int i = str.length()-1; i >= 0; --i) {
        if ('0' <= str[i] && str[i] <= '9') {
          ret = ret * 10 + str[i] - '0';
        } else if ('-' == str[i]) {
          ret *= -1;
        }
      }
      if (-(1LL<<31) <= ret && ret <= (1LL<<31)-1)
        return ret;
      return 0;
    }
};
