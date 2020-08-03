class Solution {
public:
    int numDistinct(string s, string t) {
        if (!s.length() || !t.length()) return 0;
        int* a1 = new int[s.length() + 10];
        int* a2 = new int[s.length() + 10];
        int* dp1 = a1;
        int* dp2 = a2;

        memset(dp1, 0, sizeof(int) * s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[0]) {
                if (i) dp1[i] = dp1[i-1] + 1;
                else dp1[i] = 1;
            }
            else {
                if (i) dp1[i] = dp1[i-1];
            }
        }

        swap(dp1, dp2);

        for (int j = 1; j < t.length(); j++) {
            memset(dp1, 0, sizeof(int) * s.length());
            for (int i = j; i < s.length(); i++) {
                dp1[i] = dp1[i-1];
                if (t[j] == s[i]) dp1[i] += dp2[i-1];
            }
            swap(dp1, dp2);
        }

        return dp2[s.length() - 1];
    }
};
