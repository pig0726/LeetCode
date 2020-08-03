class Solution {
public:
    string restoreString(string s, vector<int>& id) {
        string ret = s;
        for (int i = 0; i < id.size(); ++i) 
            ret[id[i]] = s[i];
        return ret;
    }
};
