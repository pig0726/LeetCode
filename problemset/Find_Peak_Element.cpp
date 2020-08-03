class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool lflag = false, rflag = false;
            if (i == 0 || nums[i] > nums[i-1]) lflag = true;
            if (i == nums.size()-1 || nums[i] > nums[i+1]) rflag = true;
            if (lflag && rflag) return i;
        }
        return -1;
    }
};
