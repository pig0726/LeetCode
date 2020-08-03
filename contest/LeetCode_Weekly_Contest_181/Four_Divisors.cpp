class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
      int ret = 0;
      for (int x : nums) {
        int cnt = 0;
        int sum = 0;
        for (int a = 1; a * a <= x; ++a) if (x % a == 0) {
          int b = x / a;
          if (a == b) {
            cnt++;
            sum += a;
          } else {
            cnt += 2;
            sum += a + b;
          }
        }
        if (cnt == 4) ret += sum;
      }
      return ret;
    }
};
