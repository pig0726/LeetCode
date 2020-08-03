class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator it = cnt.find(nums[i]);
            if (it == cnt.end()) {
                cnt.insert(make_pair(nums[i], 1));
            } else {
                it->second++;
            }
        }
        set<pair<int, int> > ans;
        for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
            ans.insert(make_pair(-it->second, it->first));
        }
        set<pair<int, int> >::iterator sit = ans.begin();
        for (int i = 0; i < k; i++) {
            ret.push_back(sit->second);
            sit++;
        }
        return ret;
    }
};
