class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    vector<int> ret;
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int a : nums) sum += a;
    int tmp = 0;
    for (int i = nums.size()-1; i >= 0; --i) {
      tmp += nums[i];
      ret.push_back(nums[i]);
      sum -= nums[i];
      if (tmp > sum) break;
    }
    return ret;
  }
};
