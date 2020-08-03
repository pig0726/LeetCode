class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int sum = 1;
        int ret = 0;
        int n = nums.size();
        int l = 0, r = 0;
        for (int r = 0; r < n; r++) {
            sum *= nums[r];
            if (sum < k) ret += r - l + 1;
            else {
                while (l <= r && sum >= k) {
                    sum /= nums[l];
                    ++l;
                }
                ret += r - l + 1;
            }
        }
        return ret;
    }
