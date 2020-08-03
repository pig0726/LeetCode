class Solution {
public:
    int climbStairs(int n) {
      vector<int> arr(1000);
      arr[0] = 0;
      arr[1] = 1;
      arr[2] = 2;
      for (int i = 3; i <= n; ++i)
        arr[i] = arr[i-1] + arr[i-2];
      return arr[n];
    }
};
