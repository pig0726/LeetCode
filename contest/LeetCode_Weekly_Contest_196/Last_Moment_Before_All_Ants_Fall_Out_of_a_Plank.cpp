class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = -INT_MAX;
        if (!left.empty())
            for (int x : left) ans = max(ans, x);
        
        int ans2 = -INT_MAX;
        if (!right.empty())
            for (int x : right) ans2 = max(ans2, n-x);
        
        return max(ans, ans2);
    }
};
