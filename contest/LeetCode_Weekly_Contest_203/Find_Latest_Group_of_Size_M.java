class Solution {
    class UnionFind {
        int[] parent, size;
        public UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 0;
            }
        }
        int find(int u) {
            if (parent[u] == u) return u;        
            parent[u] = find(parent[u]);
            return parent[u];
        }
        boolean union(int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return false;
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            return true;
        }
    }
    
    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        UnionFind uf = new UnionFind(n);
        int ans = -1;
        for (int step = 0; step < n; step++) {
            int position = arr[step] - 1;
            uf.size[position] = 1;
            int[] neighs = {position - 1, position + 1};
            for (int neigh : neighs) {
                if (neigh < 0 || neigh >= n) continue;
                if (uf.size[neigh] > 0) {
                    if (uf.size[uf.find(neigh)] == m) ans = step;
                    uf.union(position, neigh);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (uf.size[uf.find(i)] == m) {
                ans = n;
                break;
            }
        }
        return ans;
    }
}

