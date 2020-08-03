class Solution {
public:
    bool check(int idx, int n, const vector<int>& line) {
        for (int i = idx; i < n; ++i) 
            if (line[i]) 
                return false;
        return true;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            bool flag = false;
            for (int k = i-1; k < n; ++k)
                if (check(i, n, grid[k])) {
                    flag = true;
                    for (int j = k; j >= i; --j) {
                        swap(grid[j], grid[j-1]);
                        ++ret;
                    }
                    break;
                }
            if (!flag) return -1;
        }
        return ret;
    }
};
