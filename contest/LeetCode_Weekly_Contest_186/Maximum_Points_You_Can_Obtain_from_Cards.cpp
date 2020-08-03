class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        vector<int> a, b;
        a.push_back(cp[0]);
        for (int i = 1; i < cp.size(); ++i) 
            a.push_back(a.back() + cp[i]);
        
        b.push_back(cp.back());
        for (int i = cp.size()-2; i >=0 ;--i) 
            b.push_back(b.back() + cp[i]);
        
        int ret = 0;
        for (int i = 0; i <= k; ++i) {
            int av = i == 0 ? 0 : a[i-1];
            int j = k - i;
            int bv = j == 0 ? 0 : b[j-1];
            ret = max(ret, av + bv);
        }
        return ret;
    }
};
