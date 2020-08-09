const int N = 100005;
int jp[N];
int dp[N];

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        memset(jp, -1, sizeof jp);
        memset(dp, -1, sizeof dp);
        map<int, int> pos;
        
        dp[n] = 0;
        pos[0] = n;
        
        int ret = 0;
        int suffix = 0;
        for (int i = n-1; i >= 0; --i) {
            dp[i] = dp[i+1];
            suffix += nums[i];
            int v = suffix - target;
            if (pos.count(v)) {
                int p = pos[v];
                dp[i] = max(dp[i], dp[p] + 1);    
            }
            pos[suffix] = i;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
