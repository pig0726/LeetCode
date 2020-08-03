class Solution {
public:
    using ll = long long;

    int FinalResult(ll ret, int flag) {
      ret *= flag;
      if (ret < INT_MIN) return INT_MIN;
      else if (ret > INT_MAX) return INT_MAX;
      return ret;
    }

    bool IsOk(ll ret, int flag) {
      ret *= flag;
      if (INT_MIN <= ret && ret <= INT_MAX)
        return true;
      else return false;
    }

    int myAtoi(string str) {
      ll ret = 0;
      int flag[2] = {0, 0};
      int n = str.length();

      for (int i = 0; i < n; ++i) {
        if (' ' == str[i]) {
          if (!flag[1]) continue;
          else return FinalResult(ret, flag[0]);
        } else if ('-' == str[i]) {
          if (!flag[0]) flag[0] = -1;
          else return FinalResult(ret, flag[0]);
          flag[1] = 1;
        } else if ('+' == str[i]) {
          if (!flag[0]) flag[0] = 1;
          else return FinalResult(ret, flag[0]);
          flag[1] = 1;
        } else if ('0' <= str[i] && str[i] <= '9') {
          if (!flag[0]) flag[0] = 1;
          flag[1] = 1;
          ret = ret * 10 + str[i] - '0';
          if (!IsOk(ret, flag[0]))
              return FinalResult(ret, flag[0]);
        } else {
          return FinalResult(ret, flag[0]);
        }
      }

      return FinalResult(ret, flag[0]);
    }
};
