const int MOD = 1e9+7;
using LL = long long;
const int N = 5e3+5;

LL dp[N][27];

bool is_init = false;
vector<int> validc;
vector<int> match[27];

void init() {
  if (is_init) return;
  is_init = true;
  
  int bit[27][3];
  validc.clear();
  for (int i = 0; i < 27; ++i) 
    match[i].clear();
  
  for (int i = 0; i < 27; ++i) {
    int c = i;
    bool flag = true;
    for (int k = 0; k < 3 && flag; ++k, c/=3) {
      bit[i][k] = c % 3;
      if (k && bit[i][k] == bit[i][k-1])
        flag = false;
    }
    if (flag) validc.push_back(i);
  }
  //printf("validc: %d\n", validc.size());
  
  for (int c : validc)
    for (int c1 : validc) {
      bool flag = true;
      for (int k = 0; k < 3 && flag; ++k)
        if (bit[c][k] == bit[c1][k]) 
          flag = false;
      if (flag) match[c].push_back(c1); 
    }
}

class Solution {
public:
    int numOfWays(int n) {
      init();
      
      memset(dp, 0, sizeof(dp));
      for (int c : validc) dp[0][c] = 1;
      
      for (int i = 1; i < n; ++i) 
        for (int c : validc) 
          for (int c1 : match[c]) 
            dp[i][c] = (dp[i][c] + dp[i-1][c1]) % MOD;
      
      LL ret = 0;
      for (int c : validc) ret = (ret + dp[n-1][c]) % MOD;
      return ret;
    }
};
