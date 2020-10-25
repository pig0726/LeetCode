class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        char ret = kp[0];
        int maxv = rt[0];
        
        for (int i = 1; i < rt.size(); i++) {
            int v = rt[i] - rt[i-1];
            if (v > maxv || (v == maxv && kp[i] > ret)) {
                maxv = v;
                ret = kp[i];
            }
        }
        
        return ret;
    }
};
