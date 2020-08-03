class Solution {
public:
    using pii = pair<int, int>;
    using PQ = priority_queue<pii>;
    PQ pq;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        while (!pq.empty()) pq.pop();
        pq.push(make_pair(dp[0], 0));
        
        int ret = dp[0];
        for (int i = 1; i < n; ++i) {
            int idx = -1;
            while (!pq.empty()) {
                pii p = pq.top();
                if (p.second + k < i) pq.pop();
                else {
                    idx = p.second;
                    break;
                }
            }
            if (idx == -1) assert(0);
            
            dp[i] = nums[i];
            dp[i] = max(dp[i], dp[idx] + nums[i]);
            ret = max(ret, dp[i]);
            
            pq.push(make_pair(dp[i], i));
        }
        return ret;
    }
};
