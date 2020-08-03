class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ret;
      int n = matrix.size();
      if (!n) return ret;
      int m = matrix[0].size();
      if (!m) return ret;   
      
      int str = 0, stc = 0;
      int rlen = n, clen = m;
      
      while (rlen > 0 && clen > 0) {
        if (clen == 1) {
          for (int i = 0; i < rlen; ++i) ret.push_back(matrix[str+i][stc]);
          break;
        }
        if (rlen == 1) {
          for (int i = 0; i < clen; ++i) ret.push_back(matrix[str][stc+i]);
          break;
        }
        for (int i = 0; i < clen-1; ++i) 
          ret.push_back(matrix[str][stc + i]);
        for (int i = 0; i < rlen-1; ++i)
          ret.push_back(matrix[str + i][stc + clen - 1]);
        for (int i = 0; i < clen-1; ++i)
          ret.push_back(matrix[str + rlen - 1][stc + clen - 1 - i]);
        for (int i = 0; i < rlen-1; ++i)
          ret.push_back(matrix[str + rlen - 1 - i][stc]);
        ++str;
        ++stc;
        rlen -= 2;
        clen -= 2;
      }
      return ret;
    }
};
