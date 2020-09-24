const int D = 365;
int DAYS[] = {1, 7, 30};
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> f(D + 40, 0);
        unordered_set<int> s;
        for (int day : days) s.insert(day);
        for (int i = D; i >= 1; i--) {
            if (s.find(i) == s.end()) {
                f[i] = f[i + 1];
            } else {
                int ans = 1000 * D;
                for (int j = 0; j < 3; j++) {
                    ans = min(ans, costs[j] + f[i + DAYS[j]]);
                }
                f[i] = ans;
            }
        } 
        return f[1];
    }
};

