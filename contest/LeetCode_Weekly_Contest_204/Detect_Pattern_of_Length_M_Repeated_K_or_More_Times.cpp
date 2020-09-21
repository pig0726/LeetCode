class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int len = m * k;
        int n = arr.size();
        for (int i = 0; i + len <= n; ++i) {
            bool flag = true;
            for (int j = i; j < i+len; j += m) {
                for (int idx = 0; idx < m; idx++)
                    if (arr[i+idx] != arr[j+idx]) {
                        flag = false;
                        break;
                    }
                if (!flag) break;
            }
            if (flag) return true;
        }
        return false;
    }
};
