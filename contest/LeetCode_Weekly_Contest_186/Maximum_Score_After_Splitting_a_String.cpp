class Solution {
public:
    int maxScore(string s) {
        int ret = 0;
        for (int m = 0; m < s.length()-1; ++m) {
            int l = 0, r = 0;
            for (int j = 0; j <= m; ++j) 
                if (s[j] == '0') l++;
            for (int j = m+1; j < s.length(); ++j) 
                if (s[j] == '1') r++;
            ret = max(ret, l+r);
        }
        return ret;
    }
};
