class Solution {
    public int minOperations(int n) {
        int ret = 0;
        int mid = n; // (1 + 2 * (n-1) + 1) >> 1 
        for (int i = 0; i < (n+1)>>1; ++i) {
            int x = 2 * i + 1;
            ret += mid - x;
        }
        return ret;
    }
}
