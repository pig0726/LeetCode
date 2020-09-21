class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == 0)
                it = nums.erase(it);
            else
                it++;
        }
        int delta = size - nums.size();
        while (delta--)
            nums.push_back(0);
    }
};
