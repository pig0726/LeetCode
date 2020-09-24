class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int res = 0;
        int low = prices[0];
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - low);
            low = min(low, prices[i]);
        }
        return res;
    }
};

