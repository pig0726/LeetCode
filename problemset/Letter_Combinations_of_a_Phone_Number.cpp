class Solution {
public:
    inline static const std::vector<std::string> mapping{"abc", "def", "ghi",
      "jkl", "mno", "pqrs", "tuv", "wxyz"};

    char buff[1024];
    int n;
    std::vector<std::string> ret;

    void dfs(const std::string& str, int idx) {
      if (idx == n) {
        ret.emplace_back(std::string(buff));
        return;
      }
      int x = str[idx] - '0' - 2;
      const std::string& tar = mapping[x];

      for (auto& c : tar) {
        buff[idx] = c;
        dfs(str, idx+1);
      }
    }

    vector<string> letterCombinations(string digits) {
      n = digits.size();
      if (!n) return ret;
      buff[n] = 0;
      dfs(digits, 0);
      return ret;
    }
};
