class Solution {
public:
    using pii = pair<int, int>;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pii> data(n);
        for (int i = 0; i < n; i++)
            data[i] = make_pair(ages[i], scores[i]);
        sort(data.begin(), data.end());

        vector<int> dp(n);

        int ret = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = data[i].second;

            for (int j = 0; j < i; j++) {
                if (data[j].first == data[i].first || data[j].second <= data[i].second) {
                    dp[i] = max(dp[i], dp[j] + data[i].second);
                }
            }

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
