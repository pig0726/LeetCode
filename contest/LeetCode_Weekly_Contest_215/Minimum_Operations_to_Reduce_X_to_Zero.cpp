class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> pmap;
        
        int n = nums.size();
        int sum = nums[0];
        pmap[sum] = 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            pmap[sum] = i;
        }
        
    
        int ret = n+10;
        
        sum = 0;
        
        if (pmap.count(x)) {
            ret = min(ret, pmap[x]+1);
        }
        for (int cur = n-1; cur >= 0; cur--) {
            sum += nums[cur];
            if (sum > x) break;
            
            if (sum == x) {
                ret = min(ret, n - cur);
                break;
            }
            
            int delta = x - sum;
            if (pmap.count(delta) == 0) continue;
            int pos = pmap[delta];
            if (pos >= cur) continue;
            
            ret = min(ret, pos + 1 + n - cur);
        }
        
        if (ret > n) ret = -1;
        return ret;
    }
};
