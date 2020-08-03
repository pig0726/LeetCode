class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> ret;
      int n = digits.size();
      int c = 1;
      for (int i = n-1; i >= 0; --i) {
        int val = digits[i] + c;
        int x = val % 10;
        c = val / 10;
        ret.push_back(x);
      }
      if (c) ret.push_back(c);
      reverse(ret.begin(), ret.end());
      return ret;
    }
};
