class Solution {
public:
    int binary_search(vector<int>& nums, int st, int ed, int target) {
      auto it = std::lower_bound(nums.begin()+st, nums.begin()+ed, target);
      int pos = it - nums.begin();
      if (st <= pos && pos < ed && nums[pos] == target) 
        return pos;
      else return -1;
    }
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      if (nums.back() >= nums.front())
        return binary_search(nums, 0, nums.size(), target);
      
      int low = 0, high = nums.size()-1, pos = -1;
      while (low <= high) {
        int mid = (low + high) >> 1;
        if (nums.front() <= nums[mid]) {
          pos = mid;
          low = mid + 1;
        } else high = mid - 1;
      }
      assert(pos != -1);
      int ret = binary_search(nums, 0, pos+1, target);
      if (ret != -1) return ret;
      return binary_search(nums, pos+1, nums.size(), target);
    }
};
