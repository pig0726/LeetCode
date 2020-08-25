const int N = 100005;
int p[N], cnt[N];

class Solution {
public:
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        int ans = 0, ret = -1;
        for (int i = 0; i < n; ++i) 
            p[i] = -1, cnt[i] = 0;
            
        for (int ith = 0; ith < n; ith++) {
            int a = arr[ith];
            p[a-1] = a-1;
            cnt[a-1] = 1;
            
            if (a-1 > 0 && p[a-2] != -1) {
                int lrt = find(a-2);
                int lcnt = cnt[lrt];
                if (lcnt == m) ans--;
                p[lrt] = a-1;
                cnt[a-1] += lcnt;
            }
            
            if (a-1 < n-1 && p[a] != -1) {
                int rrt = find(a);
                int rcnt = cnt[rrt];
                if (rcnt == m) ans--;
                p[rrt] = a-1;
                cnt[a-1] += rcnt;
            }
        
            if (cnt[a-1] == m) ans++;
            
            if (ans) ret = ith + 1;
        }
        return ret;
    }
};
