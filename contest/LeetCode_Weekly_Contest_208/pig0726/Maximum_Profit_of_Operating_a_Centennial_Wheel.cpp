class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cs, int bs, int rc) {
        int cnt = 0;
        int wait = 0;
        int round = 1;
        int maxval = -INT_MAX;
        int idx = -1;
        
        int n = cs.size();
        for (int i = 0; i < n || wait > 0; ++i, round++) {
            if (i < n) wait += cs[i];
            int x = min(wait, 4);
            wait -= x;
            cnt += x;
            
            int val = cnt * bs - round * rc;
            if (val > 0 && val > maxval) {
                maxval = val;
                idx = round;
            }
        }
        
        return idx;
    }
};
