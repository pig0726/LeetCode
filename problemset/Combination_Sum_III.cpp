class Solution {
public:
  void dfs(const int cnt, const int tar, int sum, int dep, vector<int>& ans, vector<vector<int> >& ret) {
    if (cnt == 0) {
      if (sum == tar) {
        ret.push_back(ans);
      }
      return;
    }

    if (dep >= 10) return;

    dfs(cnt, tar, sum, dep+1, ans, ret);
    if (sum + dep > tar) return;
    ans.push_back(dep);
    dfs(cnt-1, tar, sum+dep, dep+1, ans, ret);
    ans.pop_back();
  }


  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > ret;
    vector<int> ans;
    dfs(k, n, 0, 1, ans, ret);
    return ret;
  }
};
