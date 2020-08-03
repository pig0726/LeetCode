class Solution {
public:
  int cal(int len) {
    return (1+(len-3+1))*(len-3+1)/2;
    // int sum = 0;
    // for (int l = 3; l <= len; l++) {
    //   sum += len - l + 1;
    // }
    // return sum;
  }

  int solve(int l, int r) {
    if (r - l >= 2) return cal(r-l+1);
    return 0;
  }
  int numberOfArithmeticSlices(vector<int>& A) {
    int l = 0, r = 1, n = A.size(), ret = 0;
    while (l < n) {
      if (r == n) {
        ret += solve(l, r-1);
        break;
      }

      if (r-l >1 && A[r] - A[r-1] != A[r-1] - A[r-2]) {
        ret += solve(l, r-1);
        l = r-1;
      } else {
        r++;
      }
    }
    return ret;
  }
};
