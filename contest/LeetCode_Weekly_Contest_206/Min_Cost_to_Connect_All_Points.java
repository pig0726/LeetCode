class Solution {
    class Edge {
        int u, v, w;
    };

    int n = 0;
    Edge[] e = new Edge[1000005];
    int[] p = new int[1005];

    int find(int u) {
        if (u == p[u]) return u;
        p[u] = find(p[u]);
        return p[u];
    }
    public int minCostConnectPoints(int[][] points) {
        n = points.length;

        int k = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1];
                int dist = Math.abs(xi - xj) + Math.abs(yi - yj);
                e[k] = new Edge();
                e[k].u = i;
                e[k].v = j;
                e[k].w = dist;
                k++;
            }

        Arrays.sort(e, 0, k, new Comparator<Edge>() {
            public int compare(Edge o1, Edge o2) {
                return o1.w - o2.w;
            }
        });

        for (int i = 0; i < n; ++i) p[i] = i;

        int ret = 0;
        for (int i = 0; i < k; ++i) {
            int u = e[i].u,  v = e[i].v, w = e[i].w;
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) continue;
            p[pu] = pv;
            ret += w;
        }
        return ret;
    }
}
