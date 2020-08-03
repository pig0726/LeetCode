class Solution {
public:
    int numTeams(vector<int>& rt) {
      int ret = 0;
      int n = rt.size();
      for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
          for (int k = j+1; k < n; ++k) {
            if (rt[i] < rt[j] && rt[j] < rt[k]) ++ret;
            if (rt[i] > rt[j] && rt[j] > rt[k]) ++ret;
          }
      return ret;
    }
};
