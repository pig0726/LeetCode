class Solution {
public:
    void cal(string& s, int* cnt, int *need, int& l, int& r, int& st, int& ed, int& mind) {
        while (l <= r) {
            if (r-l+1 < mind) {
                st = l;
                ed = r;
                mind = r-l+1;
            }
            int x = s[l];
            cnt[x]--;
            l++;
            if (cnt[x] < need[x]) {
                return;
            }
        }
    }

    string minWindow(string s, string t) {
        int need[512];
        int cnt[512];
        memset(need, 0, sizeof need);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < t.length(); i++) {
            need[t[i]]++;
        }
        int st = -1;
        int ed = -1;

        int total = t.length();
        int num = 0;
        int l = 0;
        int r = 0;
        int mind = INT_MAX;
        while (r < s.length()) {
            int x = s[r];
            cnt[x]++;
            if (need[x]) {
                if (cnt[x] <= need[x]) num++;
                if (num == total) {
                    cal(s, cnt, need, l, r, st, ed, mind);
                    num--;
                }
                r++;
            } else {
                r++;
            }
        }

        if (st == -1) return "";
        else return s.substr(st, ed-st+1);
    }
};
