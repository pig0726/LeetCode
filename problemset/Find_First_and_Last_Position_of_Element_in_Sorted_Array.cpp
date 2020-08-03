class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      std::vector<int> ret{-1, -1};
      auto it = std::lower_bound(nums.begin(), nums.end(), target);
      if (it == nums.end() || *it != target) return ret;
      auto it2 = std::upper_bound(nums.begin(), nums.end(), target);
      ret[0] = it - nums.begin();
      ret[1] = it2 - nums.begin() - 1;
      return ret;
    }
};
