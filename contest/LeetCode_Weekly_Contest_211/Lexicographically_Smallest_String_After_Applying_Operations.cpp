class Solution {
public:
    unordered_set<string> hs;
    int limit = 100000;
    string ret;
    
    void dfs(const string& s, int a, int b, int cur) {
        if (hs.count(s) || cur >= limit) return;
        
        hs.insert(s);
        
        ret = min(ret, s);
        
        string ss = s;
        for (int i = 1; i < ss.length(); i += 2) {
            ss[i] = ((ss[i] - '0' + a) % 10) + '0';
        }
        
        dfs(ss, a, b, cur+1);

        ss = s.substr(s.length()-b, b) + s.substr(0, s.length() - b);
        dfs(ss, a, b, cur+1);
    }
    
    string findLexSmallestString(string s, int a, int b) {
        ret = s;
        dfs(s, a, b, 0);
        return ret;
    }
};
