class Solution {
public:
    const static inline string PUSH = "Push";
    const static inline string POP = "Pop";
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int curx = 1;
        for (int i = 0; i < target.size(); ) {
            const int& x = target[i];
            if (curx < x) {
                ret.push_back(PUSH);
                ret.push_back(POP);
                curx++;
            } else if (curx == x) {
                ret.push_back(PUSH);
                ++i;
                curx++;
            }
        }
        return ret;
    }
};