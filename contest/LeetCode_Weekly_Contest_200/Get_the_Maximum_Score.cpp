using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 100005;

ll dp[2][N];

class Solution {
public:
    vector<vector<int>> nums;
    vector<vector<int>> jumps;
    int len[2];
    
    ll dfs(int idx, int pos) {
        if (pos >= len[idx]) return 0;
        if (dp[idx][pos] != -1) return dp[idx][pos];
        
        ll& ret = dp[idx][pos];
        ret = 0;
        
        ret = max(ret, 1LL * nums[idx][pos] + dfs(idx, pos+1));
        if (jumps[idx][pos] != -1) {
            int to = jumps[idx][pos];
            ret = max(ret, dfs(1-idx, to));
        }
        return ret;
                    
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        nums.push_back(nums1);
        nums.push_back(nums2);
        len[0] = nums1.size();
        len[1] = nums2.size();
        
        jumps.push_back(vector<int>(len[0], -1));
        jumps.push_back(vector<int>(len[1], -1));
        
        int a = 0, b = 0;
        while (a < len[0] && b < len[1]) {
            if (nums1[a] == nums2[b]) {
                jumps[0][a] = b;
                jumps[1][b] = a;
                a++;
                b++;
            } else if (nums1[a] > nums2[b]) {
                b++;
            } else {
                a++;
            }
        }
        
        memset(dp, -1, sizeof dp);
        ll ret = 0;
        ret = max(ret, dfs(0, 0));
        ret = max(ret, dfs(1, 0));
        
        return ret % MOD;
    }
};
