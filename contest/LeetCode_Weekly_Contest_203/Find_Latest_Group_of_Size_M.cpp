const int N = 100000;

class UnionFind {
public:
    int parent[N + 1], size[N + 1];
    UnionFind(int n) {
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
    bool unioning(int u, int v) {
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
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        UnionFind uf(n);
        int ans = -1;
        for (int step = 0; step < n; step++) {
            int position = arr[step] - 1;
            uf.size[position] = 1;
            int neighs[] = {position - 1, position + 1};
            for (int neigh : neighs) {
                if (neigh < 0 || neigh >= n) continue;
                if (uf.size[neigh] > 0) {
                    if (uf.size[uf.find(neigh)] == m) ans = step;
                    uf.unioning(position, neigh);
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
};

