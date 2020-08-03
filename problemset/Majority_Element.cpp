class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0 || ret == nums[i]) {
                cnt++;
                ret = nums[i];
            } else {
                cnt--;
            }
        }
        return ret;
    }
};
