class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = 0;
        int maxv = 0;
        int minv = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                maxv = nums[i];
                minv = nums[i];
                ret = maxv;
                continue;
            }

            int new_maxv = nums[i];
            int new_minv = nums[i];

            if (nums[i] > 0) {
                new_maxv = max(new_maxv, nums[i] * maxv);
                new_minv = min(new_minv, nums[i] * minv);
            } else {
                new_maxv = max(new_maxv, nums[i] * minv);
                new_minv = min(new_minv, nums[i] * maxv);
            }

            maxv = new_maxv;
            minv = new_minv;

            ret = max(ret, maxv);
        }

        return ret;
    }
};
