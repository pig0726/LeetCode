class Solution {
public:
    inline bool isOk(const char c) {
        if ('0' <= c && c <= '9') return true;
        if ('e' == c || '.' == c || '-' == c || '+' == c) 
            return true;
        return false;
    }
    bool isInteger(const std::string& s) {
        vector<int> op[2];
        int n = s.length();
        if (!n) return false;
        int dig_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') op[0].push_back(i);
            else if (s[i] == '+') op[1].push_back(i);
            else if ('0' <= s[i] && s[i] <= '9') ++dig_cnt;
            else return false;
        }
        if (op[0].size() + op[1].size() > 1) return false;
        if (op[0].size() && op[0].front() != 0) return false;
        if (op[1].size() && op[1].front() != 0) return false;
        if (!dig_cnt) return false;
        return true;
    }
    bool isDecimal(const std::string& s) {
        vector<int> op[3];
        int n = s.length();
        if (!n) return false;
        int dig_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') op[0].push_back(i);
            else if (s[i] == '+') op[1].push_back(i);
            else if (s[i] == '.') op[2].push_back(i);
            else if ('0' <= s[i] && s[i] <= '9') ++dig_cnt;
            else return false;
        }
        if (op[0].size() + op[1].size() > 1) return false;
        if (op[0].size() && op[0].front() != 0) return false;
        if (op[1].size() && op[1].front() != 0) return false;
        if (op[2].size() > 1) return false;
        if (!dig_cnt) return false;
        return true;
    }
    bool isNumber(string s) {
        int n = s.length();
        int st = 0, ed = n - 1;
        while (st < n && s[st] == ' ') st++;
        if (st >= n) return false;
        while (ed >= 0 && s[ed] == ' ') ed--;
        s = s.substr(st, ed - st + 1);
        n = s.length();
        for (int i = 0; i < n; ++i) {
            if (!isOk(s[i])) return false;
        }
        size_t epos = s.find('e');
        if (epos == std::string::npos)
            return isDecimal(s);
        else {
            auto Lp = s.substr(0, epos);
            auto Rp = s.substr(epos+1, n-epos-1);
            bool fL = isDecimal(Lp);
            bool rL = isInteger(Rp);
            if (fL && rL) return true;
            else return false;
        }
    }
};
