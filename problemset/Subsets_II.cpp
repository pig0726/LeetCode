class Solution {
public:
    void dfs(int idx, int size, vector<pair<int, int> >& data, vector<int>& ans, vector<vector<int> >& ret) {
        if (idx == size) {
            ret.push_back(ans);
            return;
        }

        for (int i = 0; i <= data[idx].second; i++) {
            if (i) ans.push_back(data[idx].first);
            dfs(idx+1, size, data, ans, ret);
        }
        for (int i = 0; i < data[idx].second; i++) {
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        vector<int> ans;
        int size = nums.size();
        vector<pair<int, int> > data;
        int cnt = 0;
        if (size) {
            for (int i = 0; i < size; i++) {
                if (i == 0 || nums[i] == nums[i-1]) cnt++;
                else {
                    data.push_back(make_pair(nums[i-1], cnt));
                    cnt = 1;
                }
            }
            data.push_back(make_pair(nums[size-1], cnt));
        }
        dfs(0, data.size(), data, ans, ret);
        return ret;
    }
};
