class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;

        int* dp = new int[s.length()+1];
        for (int i = 0; i < s.length(); i++) {
            if (i == 0) {
                if (s[0] != '0') dp[0] = 1;
                else dp[0] = 0;
                continue;
            }
            dp[i] = 0;
            if (s[i] != '0') dp[i] = dp[i-1];
            if ((s[i-1] == '1') || (s[i-1] == '2' && '0' <= s[i] && s[i] <= '6')) {
                if (i == 1) dp[i] += 1;
                else dp[i] += dp[i-2];
            }
        }
        int ret = dp[s.length() - 1];
        delete[] dp;
        return ret;
    }
};
