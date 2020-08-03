class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      if (!n) return false;
      int m = matrix.front().size();
      if (!m) return false;
      int tot = n * m;
      int low = 0, high = tot - 1;
      while (low <= high) {
        int mid = (low + high) >> 1;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
      }
      return false;
    }
};
