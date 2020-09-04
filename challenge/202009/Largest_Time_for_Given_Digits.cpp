class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end(), [](int x, int y) {return x > y;});
        string ret;
        char s[6];
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            if (0 <= hour && hour < 24 && 0 <= minute && minute < 60) {
                sprintf(s, "%02d:%02d", hour, minute);
                ret.assign(s);
                break;
            }
        } while (prev_permutation(A.begin(), A.end()));
        return ret;
    }
};
