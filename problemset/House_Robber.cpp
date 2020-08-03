class Solution {
public:
    int dp[100010][2];
    int rob(vector<int>& nums) {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < nums.size(); i++) {
            if (!i) {
                dp[i][1] = nums[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
