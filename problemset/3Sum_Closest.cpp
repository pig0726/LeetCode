class Solution {
public:
    int min_delta = INT_MAX;
    int tar = 0, ret = 0;

    void update(int x) {
      int tmp = abs(x - tar);
      if (tmp < min_delta) min_delta = tmp, ret = x;
    }

    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      tar = target;

      std::sort( nums.begin(), nums.end() );

      for (int i = 0; i < n; ++i) {
        for (int j = i+1, k = n - 1; j < k; ) {
          int sum = 0;
          while (j < k && ((sum=nums[i] + nums[j] + nums[k]) >= target)) {
            update(sum);
            --k;
          }
          while (j < k && ((sum=nums[i] + nums[j] + nums[k]) < target)) {
            update(sum);
            ++j;
          }
          if (!min_delta) return ret;
        }
      }
      return ret;
    }
};
