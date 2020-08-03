class Solution {
public:
    string getPermutation(int n, int k) {
      char buffer[15];
      buffer[n] = 0;
      
      vector<int> b(n, 0);
      b[n-1] = 1;
      for (int i = n-2; i >= 0; --i) b[i] = b[i+1] * (n-2-i+1);
      
      vector<bool> used(n, false);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (!used[j]) {
          if (k <= b[i]) {
            buffer[i] = j + 1 + '0';
            used[j] = true;
            break;
          }
          k -= b[i];
        }
      }
      return std::string(buffer);
    }
};
