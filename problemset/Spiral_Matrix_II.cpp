class Solution {
public:
    vector<vector<int>> generate(const int n, const int m) {
      vector<vector<int>> ret(n, vector<int>(m, 0));
      int tot = n * m, num = 1;
      int str = 0, stc = 0, rlen = n, clen = m;
      while (rlen > 0 && clen > 0) {
        //printf("=== str=%d, stc=%d, rlen=%d, clen=%d\n", str, stc, rlen, clen);
        if (clen == 1) {
          for (int i = 0; i < rlen; ++i) ret[str+i][stc] = num++;
          break;
        }
        if (rlen == 1) {
          for (int i = 0; i < clen; ++i) ret[str][stc+i] = num++;
          break;
        }
        
        for (int i = 0; i < clen-1; ++i)
          ret[str][stc+i] = num++;
        for (int i = 0; i < rlen-1; ++i)
          ret[str+i][stc+clen-1] = num++;
        for (int i = 0; i < clen-1; ++i)
          ret[str+rlen-1][stc+clen-1-i] = num++;
        for (int i = 0; i < rlen-1; ++i)
          ret[str+rlen-1-i][stc] = num++;
        str++;
        stc++;
        rlen -= 2;
        clen -= 2;
      }
      return ret;
    }
    vector<vector<int>> generateMatrix(int n) {
      return generate(n, n);
    }
};
