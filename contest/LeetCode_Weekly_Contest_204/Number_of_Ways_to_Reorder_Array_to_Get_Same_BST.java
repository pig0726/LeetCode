class Solution {
    static final int MOD = 1000000007;
    static final int N = 1005;

    int[][] f;


    int dfs(ArrayList<Integer> nums) {
        if (nums.size() <= 1) return 1;
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        int root = nums.get(0);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums.get(i) < root) a.add(nums.get(i));
            else b.add(nums.get(i));
        }

        int acnt = a.size();
        int bcnt = b.size();

        Long sum = new Long(f[acnt][bcnt]);
        sum = (sum * dfs(a)) % MOD;
        sum = (sum * dfs(b)) % MOD;

        return sum.intValue();
    }

    public int numOfWays(int[] nums) {
        ArrayList<Integer> x = new ArrayList<Integer>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) x.add(nums[i]);

        f = new int[N][N];

        for (int i = 1; i <= n; ++i)
            f[i][0] = f[0][i] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                f[i][j] = (f[i][j-1] + f[i-1][j]) % MOD;
            }

        int ret = dfs(x);
        return (ret - 1 + MOD) % MOD;
    }
}