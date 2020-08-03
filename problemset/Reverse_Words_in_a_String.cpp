class Solution {
public:
    void reverseWords(string &s) {
        int index = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                s[index++] = s[i];
                cnt = 0;
            } else {
                cnt++;
                if (cnt == 1 && i != 0) {
                    s[index++] = s[i];
                }
            }
        }
        if (index && s[index-1] == ' ') index--;
        s = s.substr(0, index);

        reverse(s.begin(), s.end());
        int head = 0;
        int end = 0;
        while(head < s.length()) {
            if (s[head] == ' ') {
                head++;
                end = head;
                continue;
            }
            while (end < s.length() && s[end] != ' ') {
                end++;
            }
            reverse(s.begin()+head, s.begin()+end);
            head = end;
        }
    }
};
