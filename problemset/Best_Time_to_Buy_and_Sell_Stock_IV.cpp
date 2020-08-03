class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        vector<int> ans1, ans2;
        int size = prices.size();
        int minp = prices[0];
        ans1.push_back(0);
        for (int i = 1; i < size; i++) {
            int ret = ans1.back();
            if (prices[i] > minp) ret = max(ret, prices[i] - minp);
            ans1.push_back(ret);
            minp = min(minp, prices[i]);
        }
        int maxp = prices[size-1];
        ans2.push_back(0);
        for (int i = size - 2; i >= 0; i--) {
            int ret = ans2.back();
            if (maxp > prices[i]) ret = max(ret, maxp - prices[i]);
            ans2.push_back(ret);
            maxp = max(maxp, prices[i]);
        }
        reverse(ans2.begin(), ans2.end());
        int ret = 0;
        for (int i = 0; i < size; i++) {
            ret = max(ret, ans1[i] + ans2[i]);
        }
        return ret;
    }
};
