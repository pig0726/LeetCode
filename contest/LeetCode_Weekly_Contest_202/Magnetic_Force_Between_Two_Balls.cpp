class Solution {
public:
    bool check(vector<int>& p, int dist, int m) {
        int n = p.size();
        int cnt = 1;
        int pre = p.front();
        for (int i = 1; cnt < m && i < n; ++i) {
            if (p[i] - pre >= dist) {
                cnt++;
                pre = p[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int low = 0, hight = 1e9, ans = 0;
        while (low <= hight) {
            int mid = (low + hight) >> 1;
            if (check(p, mid, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                hight = mid - 1;
            }
        }
        return ans;
    }
};
