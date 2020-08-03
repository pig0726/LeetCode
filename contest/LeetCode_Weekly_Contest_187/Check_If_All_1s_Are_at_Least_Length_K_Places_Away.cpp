class Solution {
public:
    const static inline int LAST = 1e6;
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -LAST;
        for (int i = 0; i < nums.size(); ++i) if (nums[i]) {
            if (i - last <= k) return false;
            last = i;
        }
        return true;
    }
};
