class Solution {
public:
    int work(vector<int>& a, unordered_map<long long, int>& cnt) {
        long long ret = 0;
        for (int x : a) {
            long long t = 1LL * x * x;
            if (cnt.count(t)) ret += cnt[t];
        }
        return ret;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        unordered_map<long long, int> cnt1, cnt2;
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = i+1; j < nums1.size(); ++j)
                cnt1[1LL * nums1[i] * nums1[j]] += 1;
        
        for (int i = 0; i < nums2.size(); ++i)
            for (int j = i+1; j < nums2.size(); ++j)
                cnt2[1LL * nums2[i] * nums2[j]] += 1;
        
        ret += work(nums1, cnt2);
        ret += work(nums2, cnt1);
        return ret;
    }
};