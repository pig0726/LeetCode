class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> ret;
      sort(nums.begin(), nums.end());
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
        if (i && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n; ++j) {
          if (j != i+1 && nums[j] == nums[j-1]) continue;
          int tmp = nums[i] + nums[j];
          for (int a = j+1, b = n-1; a < b; ++a) {
            if (a != j+1 && nums[a] == nums[a-1]) continue;
            int sum = 0;
            while (a < b && (sum = tmp + nums[a] + nums[b]) > target) --b;
            if (sum == target) {
              std::vector<int> ans{nums[i],nums[j],nums[a],nums[b]};
              ret.push_back(ans);
            }
          }
        }
      }
      return ret;
    }
};
