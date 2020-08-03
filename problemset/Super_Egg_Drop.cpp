int dp[101][10001];
class Solution {
public:
    int dfs(int K, int N) {
      if (dp[K][N] != -1) return dp[K][N];
      if (N == 0) {
        dp[K][N] = 0;
        return dp[K][N];
      }
      if (K == 1) {
        dp[K][N] = N;
        return dp[K][N];
      }
      int low = 1, high = N, ans = 0x3f3f3f3f;
      while (low <= high) {
        int mid = (low + high) >> 1;
        int v1 = dfs(K, N - mid);
        int v2 = dfs(K-1, mid - 1);
        if (v1 > v2) {
          ans = v1;
          low = mid + 1;
        } else if (v2 > v1) {
          ans = v2;
          high = mid - 1;
        } else {
          ans = v1;
          break;
        }
      }
      dp[K][N] = 1 + ans;
      return dp[K][N];
    }
    int superEggDrop(int K, int N) {
      memset(dp, -1, sizeof dp);
      return dfs(K,N);
    }
};
