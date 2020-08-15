class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it=nums.begin(); it!=nums.end(); it++) { 
            while (it+1!=nums.end() && *it==*(it+1))
                nums.erase(it+1);
        }
        return nums.size();
    }
};
