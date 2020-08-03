class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      for (int L = n; L > 1; L -= 2) {
        int r = (n - L) >> 1;
        for (int i = 0; i < L-1; ++i) {
          int c = r + i;
          int prev = -1;
          for (int k = 0; k < 4; ++k) {
            int val = matrix[r][c];
            if (k) matrix[r][c] = prev;
            prev = val;
            int rr = c;
            int cc = n - 1 - r;
            r = rr;
            c = cc;
          }
          matrix[r][c] = prev;
        }
      }
    }
};
