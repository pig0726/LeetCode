class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (k == 0) {
            bool prev = nums[0] == 0;
            for (int i = 1; i < n; i++) {
                bool curr = nums[i] == 0;
                if (prev && curr) return true;
                prev = curr;
            }
            return false;
        }
        unordered_map<int, int> s;
        s.insert(make_pair(0, -1));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            auto it = s.find(sum);
            if (it != s.end()) {
                if (i - it->second > 1) return true;
            } else {
                s.insert(make_pair(sum, i));
            }
        }
        return false;
    }
};

