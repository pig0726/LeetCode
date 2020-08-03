class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();
      int idx = 0;
      vector<vector<int>> ret;
      while (idx < n && intervals[idx][1] < newInterval[0]) {
        ret.push_back(intervals[idx]);
        ++idx;
      }
      int LB = newInterval[0], RB = newInterval[1];
      while (idx < n) {
        if (RB < intervals[idx][0]) break;
        LB = min(LB, intervals[idx][0]);
        RB = max(RB, intervals[idx][1]);
        idx++;
      }
      ret.push_back({LB, RB});
      while (idx < n) {
        ret.push_back(intervals[idx++]);
      }
      return ret;
    }
};
