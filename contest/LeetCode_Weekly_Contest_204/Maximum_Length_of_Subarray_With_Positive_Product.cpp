class Solution {
public:
    vector<int> pcnt;
    
    int get(int l, int r) {
        if (l == 0) return pcnt[r];
        else return pcnt[r] - pcnt[l-1];
    }
    
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        pcnt.assign(n,0);
        
        if (nums[0] < 0) pcnt[0] = 1;
        
        vector<int> zero;
        zero.push_back(-1);
        if (nums[0] == 0) zero.push_back(0);
        
        for (int i = 1; i < n; ++i) {
            int val = nums[i] < 0 ? 1 : 0;
            pcnt[i] = pcnt[i-1] + val;
            
            if (nums[i] == 0) zero.push_back(i);
        }
        
        zero.push_back(n);
        
        int ret = 0;
        int zcnt = zero.size();
        for (int i = 0; i < zcnt-1; ++i) {
            int l = zero[i] + 1;
            int r = zero[i + 1] - 1;
            if (l > r) continue;
            
            int cnt = get(l, r);
            if (cnt % 2 == 0) {
                ret = max(ret, r - l + 1);
            }
            else {
                for (int k = l; k < r; ++k) if (nums[k] < 0 && k != r) {
                    ret = max(ret, r - k);
                    break;
                }
                for (int k = r; k >= l; --k) if (nums[k] < 0 && k != l) {
                    ret = max(ret, k-1 - l + 1);
                    break;
                }
            }
        }
        return ret;
    }
};
