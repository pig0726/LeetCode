using ll = long long;
ll MOD = 1e9+7;

class Solution {
public:
    ll work(int l, int r) {
        if (r == l) return 0;
        int len = r - l;
        return 1LL * (1 + len) * len / 2;
    }
    int numSub(string s) {
        int n = s.length();
        int l = 0, r = 0;
        ll ret = 0;
        while (l < n) {
            if (r >= n || s[r] == '0') {
                ret = (ret + work(l, r)) % MOD;
                r++;
                l = r;
            } else ++r;
        }
        return ret;
    }
};
