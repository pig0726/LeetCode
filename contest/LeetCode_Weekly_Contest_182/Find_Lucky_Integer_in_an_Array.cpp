class Solution {
public:
    int findLucky(vector<int>& arr) {
      map<int, int> d;
      for (int a : arr) d[a] += 1;
      int ret = -1;
      for (const auto& p : d) {
        if (p.first == p.second && p.first > ret) 
          ret = p.first;
      }
      return ret;
    }
};
