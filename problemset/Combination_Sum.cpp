class Solution {
public:
    std::vector<std::vector<int>> ret;
  
    vector<int> make_ans(vector<int>& candidates, std::vector<int>& cnt) {
      vector<int> ans;
      for (int i = 0; i < cnt.size(); ++i) {
        for (int k = 0; k < cnt[i]; ++k) 
          ans.push_back(candidates[i]);
      }
      return ans;
    }
  
    void dfs(vector<int>& candidates, int target, int cur, int sum, std::vector<int>& cnt) {
      if (cur == candidates.size()) {
        if (sum == target) ret.push_back(make_ans(candidates, cnt));
        return;
      }
      
      for (int i = 0; sum + candidates[cur]*i <= target; ++i) {
        cnt.push_back(i);
        dfs(candidates, target, cur+1, sum+candidates[cur]*i, cnt);
        cnt.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      std::vector<int> cnt;
      dfs(candidates, target, 0, 0, cnt);
      return ret;
    }
};
