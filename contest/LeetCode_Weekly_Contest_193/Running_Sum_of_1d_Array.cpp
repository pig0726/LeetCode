class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ret(nums.size());
        ret[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            ret[i] = ret[i-1] + nums[i];
        return ret;
    }
};
