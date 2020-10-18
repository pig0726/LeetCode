class Solution {
public:
    int p[10005];
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<vector<int>> fs(n+1);
        for (int i = 1; i <= n; i++) p[i] = i;
        
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (i % k == 0) {
                    if (k > threshold) {
                        int pk = find(k);
                        int pi = find(i);
                        p[pk] = pi;
                    }
                    
                    if (i / k > threshold) {
                        int pk = find(i/k);
                        int pi = find(i);
                        p[pk] = pi;
                    }
                }
            }
        }
        
        vector<bool> ret;
        for (const auto& q : queries) {
            int a = q[0], b = q[1];
            int pa = find(a);
            int pb = find(b);
            ret.push_back(pa == pb);
        }
        return ret;
    }
};
