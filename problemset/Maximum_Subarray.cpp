class Solution {
public:
    int ret = INT_MIN;
    int maxSubArray(vector<int>& nums) {
      int sum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        ret = max(ret, nums[i]);
        sum += nums[i];
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
      }
      return ret;
    }
};
