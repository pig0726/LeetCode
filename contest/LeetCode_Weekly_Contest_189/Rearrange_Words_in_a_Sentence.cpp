class Solution {
public:
    string arrangeWords(string text) {
        using psi = pair<string, int>;

        vector<psi> words;
        int n = text.length();
        text[0] = text[0] - 'A' + 'a';
        int l = 0, r = 0, cnt = 0;
        while (l < n && r < n) {
            if (text[r] != ' ') ++r;
            else {
                words.push_back(make_pair(text.substr(l, r-l), cnt++));
                r++;
                l = r;
            }
        }
        if (l < n) words.push_back(make_pair(text.substr(l, r-l), cnt++));

        sort(words.begin(), words.end(), [](const psi& a, const psi& b) {
            if (a.first.length() != b.first.length())
                return a.first.length() < b.first.length();
            return a.second < b.second;
        });

        string& w = words[0].first;
        w[0] = w[0] - 'a' + 'A';
        string ret;
        for (int i = 0; i < words.size(); ++i) {
            if (i != 0) ret += " ";
            ret += words[i].first;
        }
        return ret;
    }
};
