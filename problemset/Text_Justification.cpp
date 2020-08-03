class Solution {
public:
    vector<int> presum;
  
    int cal(int i, int j) {
      int length = i == 0 ? presum[j] : presum[j] - presum[i-1];
      length += j - i;
      return length;
    }
    
    string make(const vector<string>& words, int L, int R, int maxWidth) {
      string line(maxWidth, ' ');
      if (R - L == 1) {
        for (int i = 0; i < words[L].length(); ++i) line[i] = words[L][i];
        return line;
      } 
      int idx = 0;
      if (R == words.size()) {
        for (int i = L; i < R; ++i) {
          for (int k = 0; k < words[i].length(); ++k)
            line[idx++] = words[i][k];
            idx++;
        }
        return line;    
      }
      
      int length = L == 0 ? presum[R-1] : presum[R-1] - presum[L-1];
      int relen = maxWidth - length;
      int block = relen / (R - L - 1);
      int reblock = relen % (R - L - 1);
      
     
      for (int i = L; i < R; ++i) {
        for (int k = 0; k < words[i].length(); ++k)
          line[idx++] = words[i][k];
        if (i - L + 1 <= reblock) idx += block + 1;
        else idx += block;
      }
      return line;
    }
  
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      int n = words.size();
      vector<string> ret;
      if (!n) return ret;
      presum.resize(n);
      presum[0] = words[0].length();
      for (int i = 1; i < n; ++i) 
        presum[i] = presum[i-1] + words[i].length();
      for (int i = 0, j = 0; i < n; ) {
        while (j < n && cal(i, j) <= maxWidth) ++j;
        string line = make(words, i, j, maxWidth);
        i = j;
        ret.push_back(line);
      }
      return ret;
    }
};
