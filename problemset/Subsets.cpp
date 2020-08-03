class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > ret;
        vector<int> ans;
        for (int x = 0; x < 1<<size; x++) {
            ans.clear();
            for (int i = 0; i < size; i++) {
                if (x & (1<<i)) {
                   ans.push_back(nums[i]);
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};
