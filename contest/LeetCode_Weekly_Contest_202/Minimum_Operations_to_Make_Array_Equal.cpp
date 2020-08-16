class Solution {
public:
    int minOperations(int n) {
        int mid = n, ret = 0;
        
        for (int i = 0; i < (n+1)>>1; ++i) {
            int x = 2 * i + 1;
            ret += mid - x;
        }
        return ret;
    }
};
