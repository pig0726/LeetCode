class Solution {
public:
    const static inline std::string target = "aeiou";
    int maxVowels(string s, int k) {
        vector<int> presum;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int val = 0;
            auto pos = target.find(s[i]);
            if (pos != std::string::npos) val = 1;
            
            if (!i) presum.push_back(val);
            else presum.push_back(presum.back()+val);
        }
        
        int ret = 0;
        for (int i = 0; i + k <= n; ++i) {
            int sum = 0;
            if (!i) sum = presum[i+k-1];
            else sum = presum[i+k-1] - presum[i-1];
            ret = max(ret, sum);
        }
        return ret;
    }
};
