class Solution {
public:
    inline static const int N = 1100;
    string addBinary(string a, string b) {
      char buffer[N];
      int index = 0;
      int i = a.length() - 1;
      int j = b.length() - 1;
      int c = 0;
      while (i >= 0 || j >= 0) {
        int vi = i >= 0 ? (a[i] - '0') : 0;
        int vj = j >= 0 ? (b[j] - '0') : 0;
        int val = vi + vj + c;
        int x = val % 2;
        c = val / 2;
        buffer[index++] = x + '0';
        --i;
        --j;
      }
      if (c) buffer[index++] = c + '0';
      buffer[index] = 0;
      reverse(buffer, buffer+index);
      return std::string(buffer);
    }
};
