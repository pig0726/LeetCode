class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      std::unordered_set<int> cs;
      std::unordered_set<int> rs;
      int n = matrix.size();
      int m = matrix.front().size();
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          if (!matrix[i][j]) {
            cs.insert(j);
            rs.insert(i);
          }
      for (auto& r : rs) {
        for (int i = 0; i < m; ++i) matrix[r][i] = 0;
      }
      for (auto& c : cs) {
        for (int i = 0; i < n; ++i) matrix[i][c] = 0;
      }
      return;
    }
};
