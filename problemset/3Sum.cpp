class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      std::vector<std::vector<int>> ret;
      std::sort( nums.begin(), nums.end() );
      for (int i = 0; i < n && nums[i] <= 0; ++i) {
        if (i && nums[i] == nums[i-1]) continue;
        for (int j = i+1, k = n - 1; j < k; ++j) {
          if (j != i+1 && nums[j] == nums[j-1]) continue;
          if (nums[i] + nums[j] > 0) break;
          int sum = 0;
          while (j < k && ((sum=nums[i] + nums[j] + nums[k]) > 0)) --k;
          if (sum == 0) ret.push_back({nums[i], nums[j], nums[k]});
        }
      }
      return ret;
    }
};

