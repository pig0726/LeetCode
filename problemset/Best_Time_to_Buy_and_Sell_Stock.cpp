class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            ret = max(ret, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return ret;
    }
};
