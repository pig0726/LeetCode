class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, dup = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                nums[index++] = nums[i];
                dup = 1;
            } else if (dup == 1) {
                nums[index++] = nums[i];
                dup++;
            } else {
                dup++;
            }
        }
        return index;
    }
};
