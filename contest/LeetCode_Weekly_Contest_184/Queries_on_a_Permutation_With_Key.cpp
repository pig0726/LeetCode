class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      vector<int> ret;
      deque<int> q;
      for (int i = 0; i < m; ++i) q.push_back(i+1);
      for (int v : queries) {
        for (int i = 0; i < m; ++i) if (q[i] == v) {
          ret.push_back(i);
          q.erase(q.begin() + i);
          q.push_front(v);
          break;
        }
      }
      return ret;
    }
};
