class Solution {
public:
    void append(int st, int ed, vector<string>& ret) {
        stringstream ss;
        if (st == ed) {
            ss << st;
        } else {
            ss << st;
            ss << "->";
            ss << ed;
        }
        ret.push_back(ss.str());
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int st = 0, ed = 0;
        vector<string> ret;
        int n = nums.size();
        while (st < n) {
            if (ed == n) {
                append(nums[st], nums[ed-1], ret);
                st = ed;
                continue;
            }
            
            if (ed == st) ed++;
            else {
                if (nums[ed] == nums[ed-1]+1) ed++;
                else {
                    append(nums[st], nums[ed-1], ret);
                    st = ed;
                }
            }
        }
        return ret;
    }
};
