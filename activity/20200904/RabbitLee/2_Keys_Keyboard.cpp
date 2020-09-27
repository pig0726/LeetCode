vector<int> f;

class Solution {
public:
    int dp(int n) {
        if (f[n] >= 0) return f[n];
        f[n] = n;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                f[n] = min(f[n], n / i + dp(i));
            }
        }
        return f[n];
    }
    
    int minSteps(int n) {
        f.resize(n + 1, -1);
        f[1] = 0;
        return dp(n);
    }
};

