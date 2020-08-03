class Solution {
public:
    int jump(vector<int>& nums) {
      int step = 0;
      int n = nums.size();
      int st = 0, ed = 1;
      
      while (ed < n) {
        int nxt_ed = 0;
        for (int i = st; i < ed; ++i) {
          int pos = i + nums[i];
          if (pos >= ed) nxt_ed = max(nxt_ed, pos+1);
        }
        ++step;
        st = ed;
        ed = nxt_ed;
      }
      return step;
    }
};
