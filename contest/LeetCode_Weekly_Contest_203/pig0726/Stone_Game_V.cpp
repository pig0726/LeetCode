const int N = 505;
int dp[N][N];
int ps[N];
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int get(int l, int r) {
        if (!l) return ps[r];
        return ps[r] - ps[l-1];
    }
    
    int dfs(int st, int ed) {
        if (ed == st) return 0;
        if (dp[st][ed] != INF) return dp[st][ed];
        
        int& ret = dp[st][ed];
        ret = 0;
        
        for (int mid = st; mid < ed; mid++) {
            int lv = get(st, mid);
            int rv = get(mid+1, ed);
            
            if (lv > rv) {
                ret = max(ret, rv + dfs(mid+1, ed));
            } else if (lv < rv) {
                ret = max(ret, lv + dfs(st, mid));
            } else {
                ret = max(ret, lv + dfs(st, mid));
                ret = max(ret, rv + dfs(mid+1, ed));
            }
        }
        
        return ret;
        
    }
    
    int stoneGameV(vector<int>& sv) {
        int n = sv.size();
        
        ps[0] = sv.front();
        for (int i = 1; i < n; ++i)
            ps[i] = ps[i-1] + sv[i];
        
        memset(dp, 0x3f, sizeof dp);
        
        return dfs(0, n-1);
    }
};
