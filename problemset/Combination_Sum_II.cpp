class Solution {
public:
    using pii = std::pair<int, int>;
    vector<pii> data;
    vector<vector<int>> ret;
  
    vector<int> make_ans(vector<pii>& data, vector<int>& cnt) {
      vector<int> ans;
      for (int i = 0; i < cnt.size(); ++i) {
        for (int k = 0; k < cnt[i]; ++k) 
          ans.push_back(data[i].first);
      }
      return ans;
    }
  
    void dfs(vector<pii>& data, int target, int cur, int sum, vector<int>& cnt) {
      if (cur == data.size()) {
        if (sum == target) 
          ret.push_back(make_ans(data, cnt));
        return;
      }   
      
      const auto& p = data[cur];
      for (int i = 0; i <= p.second && sum + i * p.first <= target; ++i) {
        cnt.push_back(i);
        dfs(data, target, cur+1, sum + i * p.first, cnt);
        cnt.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      if (candidates.empty()) return ret;
      sort(candidates.begin(), candidates.end());
      int cnt = 0;
      for (int i = 0; i < candidates.size(); ++i) {
        if (!i || candidates[i] == candidates[i-1]) ++cnt;
        else {
          data.push_back(make_pair(candidates[i-1], cnt));
          cnt = 1;
        }
      }
      data.push_back(make_pair(candidates.back(), cnt));
      
      vector<int> used;
      dfs(data, target, 0, 0, used);
      return ret;
    }
};
