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
};
