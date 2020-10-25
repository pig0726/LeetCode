class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;
        
        int m = l.size();
        for (int i = 0; i < m; i++) {
            int a = l[i], b = r[i];
            int len = b - a + 1;
            vector<int> tmp(len);
            for (int k = 0; k < len; k++)
                tmp[k] = nums[a + k];
            
            sort(tmp.begin(), tmp.end());
            bool flag = true;
            for (int k = 2; k < tmp.size(); k++) {
                if (tmp[k] - tmp[k-1] != tmp[1] - tmp[0]) {
                    flag = false;
                    break;
                }
            }
            ret.push_back(flag);
        }
        return ret;
    }
};
