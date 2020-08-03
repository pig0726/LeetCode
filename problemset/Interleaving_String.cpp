class Solution {
public:
    bool dp[1010][1010];
    bool vis[1010][1010];
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        memset(dp, false, sizeof dp);
        memset(vis, false, sizeof vis);
        queue<pair<int, int> > que;
        que.push(make_pair(0, 0));
        dp[0][0] = true;
        vis[0][0] = true;
        while (!que.empty()) {
            pair<int, int> x = que.front();
            que.pop();
            int i = x.first, j = x.second;
            if (i+1 <= s1.size() && s1[i+1-1] == s3[i+1+j-1]) {
                dp[i+1][j] = true;
                if (!vis[i+1][j]) {
                    vis[i+1][j] = true;
                    que.push(make_pair(i+1, j));
                }
            }

            if (j+1 <= s2.size() && s2[j+1-1] == s3[i+j+1-1]) {
                dp[i][j+1] = true;
                if (!vis[i][j+1]) {
                    vis[i][j+1] = true;
                    que.push(make_pair(i, j+1));
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }
};
