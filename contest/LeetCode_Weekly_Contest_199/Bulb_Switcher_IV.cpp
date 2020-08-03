class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        for (char c : target) {
            int val = c - '0';
            if (cnt & 1 && !val) cnt++;
            else if (!(cnt&1) && val) cnt++;
        }
        return cnt;
    }
};
