char buff[102400];
class Solution {
public:
    std::vector<std::string> ret;
    string countAndSay(int n) {
      ret.push_back("1");

      for (int k = 1; k < 30; ++k) {
        const auto& str = ret.back();
        std::string now;
        int m = str.length();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
          if (!i || str[i] == str[i-1]) ++cnt;
          else {
            now += std::to_string(cnt);
            now += std::string(1, str[i-1]);
            cnt = 1;
          }
        }
        now += std::to_string(cnt);
        now += std::string(1, str.back());
        ret.push_back(now);
      }

      return ret[n-1];
    }
};
