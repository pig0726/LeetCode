class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int* dp = new int[n+10];
        for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++) {
            int low = 1, high = n, ans = -1;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (dp[mid] >= nums[i]) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (ans != -1) {
                dp[ans] = nums[i];
            }
        }
        for (int i = n; i; i--) {
            if (dp[i] != INT_MAX) return i;
        }  
        return -1;
    }
};
