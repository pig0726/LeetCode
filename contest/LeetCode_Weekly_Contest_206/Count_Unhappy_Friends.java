class Solution {
    int [][] m = new int[505][505];
    boolean[] vis = new boolean[505];

    boolean work(int x, int y, int u, int v) {
        int pu = m[x][u];
        int py = m[x][y];

        int px = m[u][x];
        int pv = m[u][v];

        if (pu < py && px < pv) return true;
        return false;
    }
    public int unhappyFriends(int n, int[][] ps, int[][] pairs) {
        for (int i = 0; i < n; ++i) vis[i] = true;

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < ps[i].length; ++k)
                m[i][ps[i][k]] = k;
        }
        for (int i = 0; i < pairs.length; ++i) {
            for (int j = 0; j < pairs.length; ++j) if (i != j) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];

                if (work(x, y, u, v)) vis[x] = false;
                if (work(y, x, u, v)) vis[y] = false;
                if (work(x, y, v, u)) vis[x] = false;
                if (work(y, x, v, u)) vis[y] = false;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
            if (!vis[i]) ++ret;
        return ret;
    }
}
