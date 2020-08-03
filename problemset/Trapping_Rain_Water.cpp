class Solution {
public:
    int trap(vector<int>& height) {
      using pii = std::pair<int, int>; // H, L
      stack<pii> stk;
      int ret = 0;
      int n = height.size();
      for (int i = 0; i < n; ++i) {
        int h = height[i];
        if (stk.empty() || stk.top().first >= h) {
          stk.push({h, 1});
          continue;
        }
        int ans = 0;
        int sumL = 0;
        int full = 0;
        while (!stk.empty()) {
          const auto& b = stk.top();
          int lastH = min(b.first, h);
          int tmp = lastH * sumL - full;
          ans += tmp;
          if (b.first > h) break;
          sumL += b.second;
          full += tmp;
          full += b.first * b.second;
          stk.pop();
        }
        ret += ans;
        stk.push({h, sumL + 1});
      }
      return ret;
    }
};
