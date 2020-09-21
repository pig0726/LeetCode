class Solution {
    
    HashMap<Integer, Integer> dp;
    
    int dfs(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        
        if (dp.containsKey(n)) return dp.get(n);
        
        int ret = Math.min(dfs(n/3) + n % 3, dfs(n/2) + n % 2) + 1;
        
        dp.put(n, ret);
        return ret;
    }
        
    public int minDays(int n) {
        dp = new HashMap<Integer, Integer>();
        return dfs(n);
    }
}
