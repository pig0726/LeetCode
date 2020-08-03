class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
      vector<string> ret;
      for (const auto& t : words) {
        for (const auto& s : words) {
          if (t != s && s.find(t) != string::npos) {
            ret.push_back(t);
            break;
          }
        }
      }
      return ret;
    }
};
