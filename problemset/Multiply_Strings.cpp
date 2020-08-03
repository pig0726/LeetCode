

class Solution {
public:
    inline static const int SIZE = 1024;
    char buffer[SIZE];
  
    std::string Add(const std::string& a, const std::string& b) {
      int c = 0;
      int n = a.length();
      int m = b.length();
      int idx = SIZE - 1;
      for (int i = n-1, j = m-1; i >= 0 || j >= 0; --i, --j) {
        int va = ((i >= 0) ? (a[i] - '0'): 0);
        int vb = ((j >= 0) ? (b[j] - '0'): 0);
        int v = va + vb + c;
        buffer[idx--] = (v % 10) + '0';
        c = v / 10;
        //printf("v=%d, c=%d\n", v, c);
      }
      if (c) buffer[idx--] = '1';
      //printf("idx=%d\n", idx);
      return std::string(buffer + idx + 1, SIZE - 1 - idx);
    }
  
    std::string Mul(const std::string& a, const int x) {
      if (!x) return "0";
      int c = 0;
      int n = a.length();
      int idx = SIZE - 1;
      for (int i = n-1; i >= 0; --i) {
        int v = (a[i] - '0') * x + c;
        buffer[idx--] = (v % 10) + '0';
        c = v / 10;
      }
      if (c) buffer[idx--] = c + '0';
      return std::string(buffer + idx + 1, SIZE - 1 - idx);
    }
  
    string multiply(string num1, string num2) {
      std::string ret;
      int n = num1.size();
      for (int i = n-1; i >= 0; --i) {
        std::string tmp = Mul(num2, num1[i] - '0');
        if (i != n-1 && tmp != "0") 
          tmp += std::string(n-1-i, '0');
        std::string ans = Add(ret, tmp);
        std::swap(ans, ret);
      }
      return ret;
    }
};
