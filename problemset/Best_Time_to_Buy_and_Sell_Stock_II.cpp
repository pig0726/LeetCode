class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int minp = prices[0];
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minp) {
                ret += prices[i] - minp;
                minp = prices[i];
            } else if (prices[i] < minp) {
                minp = prices[i];
            }
        }
        return ret;
    }
};
