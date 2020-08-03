class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      using Table = std::map<std::string, std::vector<std::string>>;
      Table data;
      for (auto& s : strs) {
        auto key = s;
        sort(key.begin(), key.end());
        data[key].push_back(s);
      }
      vector<vector<string>> ret;
      for (auto& p : data) {
        ret.emplace_back(std::move(p.second));
      }
      return ret;
    }
};
