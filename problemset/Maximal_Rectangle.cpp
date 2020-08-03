class Solution {
public:
    void solve(int st, int ed, int dlt, int* bound, vector<int>& heights) {
        stack<int> sta;
        for (int i = st; i != ed; i += dlt) {
            while (true) {
                if (sta.empty()) {
                    bound[i] = st - dlt;
                    sta.push(i);
                    break;
                }
                int idx = sta.top();
                if (heights[i] <= heights[idx]) {
                    sta.pop();
                } else {
                    bound[i] = idx;
                    sta.push(i);
                    break;
                }
            }
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int *lbound = new int[heights.size()];
        int *rbound = new int[heights.size()];
        memset(lbound, 0, sizeof(int)*heights.size());
        memset(rbound, 0, sizeof(int)*heights.size());

        solve(0, heights.size(), 1, lbound, heights);
        solve(heights.size()-1, -1, -1, rbound, heights);

        int ret = 0;
        for (int i = 0; i < heights.size(); i++) {
            ret = max(ret, heights[i] * (rbound[i]-lbound[i]-1));
        }

        delete[] lbound;
        delete[] rbound;

        return ret;
    }

    int maximalRectangle(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        int ret = 0;

        vector<int> h1(col, 0);
        vector<int> h2(col, 0);
        vector<int>* now = &h1;
        vector<int>* pre = &h2;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                (*now)[c] = matrix[r][c] == '0' ? 0 : (*pre)[c] + 1;
            }
            int ans = largestRectangleArea(*now);
            ret = max(ret, ans);
            swap(now, pre);
        }

        return ret;
    }
};
