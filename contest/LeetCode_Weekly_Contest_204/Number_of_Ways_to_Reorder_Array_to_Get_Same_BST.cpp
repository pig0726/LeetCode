const int MOD = 1e9+7;
const int N = 1005;

int f[N][N];

class Solution {
public:
    int dfs(const vector<int>& nums) {
        if (nums.size() <= 1) return 1;
        vector<int> a, b;
        int root = nums.front();
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        
        int acnt = a.size();
        int bcnt = b.size();
        
        long long sum = f[acnt][bcnt];
        sum = (sum * dfs(a)) % MOD;
        sum = (sum * dfs(b)) % MOD;
        
        return sum;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        memset(f, 0, sizeof f);
        
        for (int i = 1; i <= n; ++i)
            f[i][0] = f[0][i] = 1;
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                f[i][j] = (f[i][j-1] + f[i-1][j]) % MOD;
            }
        
        int ret = dfs(nums);
        return (ret - 1 + MOD) % MOD;
    }
};
