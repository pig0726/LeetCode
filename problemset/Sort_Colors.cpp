class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++) {
            ++cnt[nums[i]];
        }
        for (int c = 0, index = 0; c < 3; c++) {
            for (int i = 0; i < cnt[c]; i++) {
                nums[index++] = c;
            }
        }
    }
};
