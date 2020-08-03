class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> ret;
      int L = INT_MAX, R = -1, n = intervals.size();
      for (int i = 0; i < n; ++i) {
        const auto& p = intervals[i];
        if (!i || (p[0] <= R)) {
          L = min(L, p[0]);
          R = max(R, p[1]);
        } else {
          ret.push_back({L, R});
          L = p[0];
          R = p[1];
        }
      }
      if (L != INT_MAX) ret.push_back({L, R});
      return ret;
    }
};
