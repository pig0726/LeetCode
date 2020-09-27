const int M = 1e9 + 7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long middleMax = max(findMaximumSubarray(arr, true), 0);
        if (k == 1) {
            return middleMax % M;
        } else {
            long long s = 0;
            for (auto x : arr) s += x;
            long long rightMax = findMaximumSubarray(arr, false);
            reverse(arr.begin(), arr.end());
            long long leftMax = findMaximumSubarray(arr, false);
            return max(middleMax, rightMax + (s > 0 ? (k - 2) * s : 0) + leftMax) % M;
        }
    }
    
    int findMaximumSubarray(vector<int>& arr, bool middle) {
        int n = arr.size();
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i - 1], 0) + arr[i - 1];
        }
        if (middle) {
            return *(max_element(f.begin(), f.end()));
        } else {
            return f[n];
        }
    }
};

