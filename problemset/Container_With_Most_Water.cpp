class Solution {
public:
    int maxArea(vector<int>& height) {
      int lidx = 0, ridx = height.size() - 1;
      int ret = 0;
      while (lidx < ridx) {
        ret = max(ret, min(height[lidx], height[ridx]) * abs(lidx - ridx));
        if (height[lidx] <= height[ridx]) ++lidx;
        else --ridx;
      }
      return ret;
    }
};

