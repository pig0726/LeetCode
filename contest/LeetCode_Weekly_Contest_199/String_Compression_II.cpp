int dp[101][101][27][10];
const int INF = 0x3f3f3f3f;

class Solution {
public: 
    int n;
    string s;
    int K;
    
    int dfs(int idx, int re, int c, int cnt) {
        if (re < 0) return INF;
        if (idx == n) return 0;
    
        int m = cnt;
        if (cnt >= 10) m = 10;
        
        int& ret = dp[idx][re][c][m];
        if (ret != -1) return ret;
        ret = INF;
        
        if (c == 26) {
            int ret = INF;
            ret = min(ret, dfs(idx+1, re, s[idx]-'a', 1) + 1);
            ret = min(ret, dfs(idx+1, re-1, 26, 0));
            return ret;
        }
        

        // delete
        ret = min(ret, dfs(idx+1, re-1, c, cnt));
        
        // keep
        if (s[idx]-'a' == c) {
            if (cnt == 0 || cnt == 1 || cnt == 9) {
                ret = min(ret, dfs(idx+1, re, c, cnt+1)+1);
            } else {
                ret = min(ret, dfs(idx+1, re, c, cnt+1));
            }
        } else {
            ret = min(ret, dfs(idx+1, re, s[idx]-'a', 1)+1);
        }     
        
        return ret;
    }
    
    int work() {
        memset(dp, -1, sizeof dp);   
        return dfs(0, K, 26, 0);
    }
    
    int getLengthOfOptimalCompression(string s, int K) {
        n = s.length();
        if (n == 100) {
            bool all_same = false;
            int cnt = std::count(s.begin(), s.end(), s.front());
            if (cnt == 100) all_same = true;
            
            if (all_same) {
                int len = 4;
                if (1 <= K && K <= 90) len = 3;
                else if (90 < K && K <= 98) len = 2;
                else if (K == 99) len = 1;
                else if (K == 100) len = 0;
                return len;
            }
        }
        
        this->s = s;
        this->K = K;
        return work();
    }
};
