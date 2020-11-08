class Solution {
public:
    const static int N = 100000;
    const static int MOD = 1e9+7;
    int c[N+1];
    
    int lowbit(int x) { return x & (-x); }
    
    int query(int p) {
        int sum = 0;
        while (p > 0) {
            sum += c[p];
            p -= lowbit(p);
        }
        return sum;
    }
    
    void update(int p) {
        while (p <= N) {
            c[p]++;
            p += lowbit(p);
        }
    }
    
    int createSortedArray(vector<int>& ins) {
        long long ret = 0;
        for (int x : ins) {
            int va = query(x-1);
            int vb = query(x);
            int vc = query(N);
            int vd = vc - vb;
            int val = min(va, vd);
            ret = (ret + val) % MOD;
            update(x);
        }    
        return ret;
    }
};
