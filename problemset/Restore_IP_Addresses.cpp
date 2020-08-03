class Solution {
public:
    void dfs(int idx, int n, const string& s, vector<int>& ans, vector<string>& ret) {
        if (idx == n) {
            if (ans.size() != 4) return;
            string ip;
            for (int i = 0; i < ans.size(); i++) {
                stringstream ss;
                ss << ans[i];
                ip += ss.str();
                if (i != 3) ip += ".";
            }
            ret.push_back(ip);
            return;
        }

        if (ans.size() == 4) return;

        int x = 0;
        for (int i = idx; i < n; i++) {
            x = x * 10 + s[i] - '0';
            if (x > 255) break;
            ans.push_back(x);
            dfs(i+1, n, s, ans, ret);
            ans.pop_back();
            if (x == 0) break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<int> ans;
        dfs(0, s.length(), s, ans, ret);
        return ret;
    }
};
