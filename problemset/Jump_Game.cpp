class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int st = 0, ed = 1;
      while (ed < n) {
        int max_pos = -1;
        for (int i = st; i < ed; ++i)
          max_pos = max(max_pos, i + nums[i]);
        if (max_pos < ed) break;
        st = ed;
        ed = max_pos + 1;
      }
      return ed >= n;
    }
};
