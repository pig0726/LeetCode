class Solution {
public:
    bool ok(const char c) {
        if ('a' <= c && c <= 'z') return true;
        if ('A' <= c && c <= 'Z') return true;
        if ('0' <= c && c <= '9') return true;
        return false;
    }
    bool check(char a, char b) {
        if ('A' <= a && a <= 'Z') a = a - 'A' + 'a';
        if ('A' <= b && b <= 'Z') b = b - 'A' + 'a';
        return a == b;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool ret = true;
        while (ret && l < r) {
            while (l < r && !ok(s[l])) l++;
            while (l < r && !ok(s[r])) r--;
            if (!check(s[l], s[r])) ret = false;
            else {l++; r--;}
        }
        return ret;
    }
};
