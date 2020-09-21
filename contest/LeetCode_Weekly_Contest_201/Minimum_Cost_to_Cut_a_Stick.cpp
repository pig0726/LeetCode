class Solution {
public:
    int dp[101][101];
    int n;
    int dfs(int st, int ed, const vector<int>& cuts) {
        if (ed < st) return 0;

        if (dp[st][ed] != -1) return dp[st][ed];

        int L = -1, R = -1;
        if (st == 0) L = 0;
        else L = cuts[st-1];

        if (ed == cuts.size()-1) R = n;
        else R = cuts[ed+1];

        int& ret = dp[st][ed];
        ret = INT_MAX;
        int val = R - L;
        for (int i = st; i <= ed; ++i) if (L < cuts[i] && cuts[i] < R) {
            ret = min(ret, dfs(st, i-1, cuts) + dfs(i+1, ed, cuts) + val);
        }

        if (ret == INT_MAX) ret = 0;
        return ret;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        this->n = n;
        memset(dp, -1, sizeof dp);
        return dfs(0, cuts.size()-1, cuts);
    }
};
