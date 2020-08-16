class Solution {
    boolean check(int[] p, int dist, int m) {
        int n = p.length;
        int cnt = 1;
        int pre = p[0];
        for (int i = 1; cnt < m && i < n; ++i) {
            if (p[i] - pre >= dist) {
                cnt++;
                pre = p[i];
            }
        }
        return cnt >= m;
    }
    public int maxDistance(int[] p, int m) {
        Arrays.sort(p);
        int low = 0;
        int hight = 1000000000;
        int ans = 0;
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
}
