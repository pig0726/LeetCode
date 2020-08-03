class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> ret;
        int n = rowIndex - 1;
        int mid = (rowIndex+1) / 2;
        for (int i = 0; i < rowIndex; i++) {
            if (i >= mid) {
                ret.push_back(ret[rowIndex - i - 1]);
            } else {
                int m = min(i, n - i);
                if (m == 0) ret.push_back(1);
                else {
                    long long v = 1LL * ret[m - 1] * (n - m + 1) / m;
                    ret.push_back((int)v);
                }
            }
        }
        return ret;
    }
};
