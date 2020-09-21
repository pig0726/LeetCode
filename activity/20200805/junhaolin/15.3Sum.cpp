class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        map<int,int> count;
        for (int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        
        vector<int> newNums;
        for (const auto& [key, value] : count) 
            newNums.insert(newNums.end(), value > 3 ? 3 : value, key);
        
        for (int i=0; i<newNums.size(); i++) {
            for (int j=i+1; j<newNums.size(); j++) {
                int c = 0 - (newNums[i]+newNums[j]);
                if (count.find(c) != count.end()) {
                    if ((c == newNums[i] && c == newNums[j] && count[c]>=3)
                       || (c == newNums[i] && c != newNums[j] && count[c]>=2)
                       || (c != newNums[i] && c == newNums[j] && count[c]>=2) 
                       || (c != newNums[i] && c != newNums[j])) {
                        vector<int> triplet = vector<int> {newNums[i], newNums[j], c};
                        sort(triplet.begin(), triplet.end());
                        result.insert(triplet);
                    }
                }
            }
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
};
