class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        size_t size = nums.size();
        for (int i = 0; i < size; i++) {
            int delta = target - nums[i];
            map<int, int>::iterator it = m.find(delta);
            if (it != m.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
