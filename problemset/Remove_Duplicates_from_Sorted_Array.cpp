class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int idx = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (!i || nums[i] != nums[i-1])
          nums[idx++] = nums[i];
      }
      return idx;
    }
};
