class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> pos;
        int delidx = -1;
        int ret = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int L = val - limit;
            int R = val + limit;
            int maxidx = -1;
            
            while (!pos.empty() && pos.begin()->first < L) {
                maxidx = max(maxidx, pos.begin()->second);
                pos.erase(pos.begin());
            }
            
            while (!pos.empty()) {
                auto it = pos.end();
                --it;
                if (it->first <= R) break;
                maxidx = max(maxidx, it->second);
                pos.erase(it);
            }
            
            if (maxidx != -1) 
                delidx = max(delidx, maxidx);
        
            ret = max(ret, i - delidx);
            pos[nums[i]] = i;        
        }

        return ret;
    }
};
