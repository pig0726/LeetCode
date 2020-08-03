const int MOD = 1e9 + 7;
int dp[505][55][2];

class Solution {
public:
  string evil;
  vector<int> next;
  
  
  void KMPGetNext(const string& t) {
    int n = t.length();
    next.assign(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
      while (j > 0 && t[j] != t[i]) j = next[j-1];
      if (t[j] == t[i]) next[i] = j+1, ++j;
    }
  }
  
  bool Contain(const string& s, const string& t) {
    int m = t.length();
    for (int i = 0; i < s.length(); ++i)
      if (s.substr(i, m) == t) return true;
    return false;
  }
  
  int dfs(const string& s, int idx, int matched, int tight) {
    if (matched == evil.length()) return 0;
    if (idx == s.length()) return 1;
    
    int& ret = dp[idx][matched][tight];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < 26; ++i) {
      const char ch = 'a' + i;
      
      if (tight && ch > s[idx]) continue; // greater than s
      
      int new_tight = tight && ch == s[idx];
      
      int new_matched = matched;
      while (new_matched > 0 && evil[new_matched] != ch) 
        new_matched = next[new_matched-1];
      
      if (evil[new_matched] == ch) 
        new_matched++;
       
      ret = (ret + dfs(s, idx+1, new_matched, new_tight)) % MOD;
    }
    //printf("dp[%d][%d][%d]=%d\n", idx, matched, tight, ret);
    return ret;
  }
  
  int findGoodStrings(int n, string s1, string s2, string evil) {
    this->evil = evil;
    KMPGetNext(evil);
    
    memset(dp, -1, sizeof(dp));
    int ret2 = dfs(s2, 0, 0, 1);
    //printf("==================\n");
    memset(dp, -1, sizeof(dp));
    int ret1 = dfs(s1, 0, 0, 1);
    int ret = (ret2 - ret1 + MOD) % MOD;
    //printf("ret2=%d, ret1=%d, ret=%d\n", ret2, ret1, ret);
    if (!Contain(s1, evil)) ret = (ret + 1) % MOD;
    return ret;
  }
};
