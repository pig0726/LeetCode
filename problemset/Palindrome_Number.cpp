class Solution {
public:
    bool isPalindrome(int x) {
      std::string str = std::to_string(x);
      int n = str.length();
      for (int i = 0, j = n - 1; i < j; ++i, --j)
        if (str[i] != str[j]) return false;
      return true;
    }
};
