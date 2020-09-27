class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int res = 0;
        int resRound = -1;

        int wait = 0;
        int i;
        for (i = 0; i < customers.size() || wait > 0; i++) {
            if (i < customers.size()) wait += customers[i];
            if (wait > 0) {
                if (wait < 4) {
                    profit += wait * boardingCost;
                    wait = 0;
                } else {
                    profit += 4 * boardingCost;
                    wait -= 4;
                }
            }
            profit -= runningCost;
            if (profit > res) {
                res = profit;
                resRound = i + 1;
            }
        }

        return resRound;        
    }
};

