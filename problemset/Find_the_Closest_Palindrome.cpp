class Solution {
public:
    long long to_long(const string& s) {
        long long ans = 0LL;
        for (int i = 0; i < s.length(); i++) {
            ans = ans * 10LL + s[i] - '0';
        }
        return ans;
    }

    void make(long long x, vector<long long>& rets) {
        if (x == 0) return;
        string s = to_string(x);
        string s1 = s;
        reverse(s1.begin(), s1.end());
        rets.push_back(to_long(s + s1));

        if (s.length() == 1) return;

        s1 = s.substr(0, s.length()-1);
        reverse(s1.begin(), s1.end());
        rets.push_back(to_long(s + s1));
    }

    string nearestPalindromic(string n) {
        if (n.length() == 1) {
            long long x = to_long(n) - 1;
            return to_string(x);
        }

        vector<long long> rets;

        string x(n.length()-1, '9');
        rets.push_back(to_long(x));

        x = string(n.length()+1, '0');
        x[0] = x[x.length()-1] = '1';
        rets.push_back(to_long(x));

        string tmp = n.substr(0, (n.length()+1)/2);
        for (int d = -1; d <= 1; d++) {
            long long i = to_long(tmp) + d;
            make(i, rets);
        }

        long long ret = 0;
        long long mind = (1LL << 63) - 1;
        long long n_i = to_long(n);
        for (int i = 0; i < rets.size(); i++) {
            if (rets[i] == n_i) continue;
            if (abs(rets[i] - n_i) < mind) {
                mind = abs(rets[i] - n_i);
                ret = rets[i];
            } else if (abs(rets[i] - n_i) == mind && rets[i] < ret) {
                ret = rets[i];
            }
        }

        return to_string(ret);
    }
};
