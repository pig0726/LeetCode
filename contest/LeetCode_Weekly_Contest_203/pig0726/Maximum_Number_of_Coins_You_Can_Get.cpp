class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), [](const int a, const int b) { return a > b; });
        int n = piles.size()/3;
        int ret = 0;
        for (int i = 1, j = 0; j < n; i += 2, ++j)
            ret += piles[i];
        return ret;
    }
};
