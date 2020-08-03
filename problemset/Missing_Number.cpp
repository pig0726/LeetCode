class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (0 + size) * (size+1) / 2;
        int x = 0;
        for (int i = 0; i < size; i++) x += nums[i];
        return sum - x;
    }
};
