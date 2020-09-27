class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        int res = nums[0];
        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i - 1], 0) + nums[i - 1];
            res = max(res, f[i]);
        }
        return res;
    }
};

