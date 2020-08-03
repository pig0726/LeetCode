const int N = 505;

class Solution {
public:
    string reformat(string s) {
        vector<char> ch[2];
        for (int i = 0; i < s.length(); ++i) {
            int id = 1;
            if ('0' <= s[i] && s[i] <= '9') id = 0;
            ch[id].push_back(s[i]);
        }
        
        if (ch[0].size() < ch[1].size()) 
            std::swap(ch[0], ch[1]);
        if (ch[0].size() - ch[1].size() > 1) 
            return "";
        
        char buf[N];
        int idx = 0, id[2]{0,0};
        for (int i = 0; i < ch[1].size(); ++i) {
            buf[idx++] = ch[0][id[0]++];
            buf[idx++] = ch[1][id[1]++];
        }
        if (ch[0].size() > ch[1].size()) 
            buf[idx++] = ch[0].back();
        buf[idx] = 0;
        return string(buf);
    }
};
