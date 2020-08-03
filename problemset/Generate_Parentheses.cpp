class Solution {
public:
    char buff[1024];
    std::vector<std::string> ret;
    void dfs(const int n, const int lcnt, const int rcnt) {
      if (rcnt == lcnt && lcnt == n) {
        std::string ans(buff);
        ret.push_back(ans);
        return;
      }
      if (rcnt < lcnt) {
        buff[lcnt+rcnt] = ')';
        dfs(n, lcnt, rcnt+1);
      }
      if (lcnt < n) {
        buff[lcnt+rcnt] = '(';
        dfs(n, lcnt+1, rcnt);
      }
    }
    vector<string> generateParenthesis(int n) {
      buff[n<<1] = 0;
      dfs(n, 0, 0);
      return ret;
    }
};
