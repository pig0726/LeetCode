class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ret = 0;
        while (n >= m) {
            ret += m;
            n -= m;
            n++;
        }
        ret += n;
        return ret;
    }
};
