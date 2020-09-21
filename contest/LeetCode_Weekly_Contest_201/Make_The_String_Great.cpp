class Solution {
public:
    string makeGood(string s) {
        string ret;
        for (char c : s) {
            if (!ret.empty() && (
                ('a' <= ret.back() && ret.back() <= 'z' && 'A' <= c && c <= 'Z' && ret.back()-'a' == c-'A') || 
                ('A' <= ret.back() && ret.back() <= 'Z' && 'a' <= c && c <= 'z' && ret.back()-'A' == c-'a'))) 
                ret.pop_back();
            else ret += c;
        }
        return ret;
    }
};
