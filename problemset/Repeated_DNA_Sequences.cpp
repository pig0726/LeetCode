class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string subs = "";
        vector<string> ret;
        unordered_map<string, int> table;
        for (int i = 0; i < s.length(); i++) {
            subs += s.substr(i, 1);
            if (subs.length() > 10) subs = subs.substr(1, 10);
            if (subs.length() == 10) {
                unordered_map<string, int>::iterator it = table.find(subs);
                if (it == table.end()) {
                    table.insert(make_pair(subs, 1));
                } else if (it->second == 1) {
                    ret.push_back(subs);
                    it->second++;
                } else {
                    it->second++;
                }
            }
        }
        return ret;
    }
};
