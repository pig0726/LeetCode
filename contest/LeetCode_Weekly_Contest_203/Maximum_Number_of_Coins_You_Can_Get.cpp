bool compare(int i1, int i2) {
    return i1 > i2;
}

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(piles.begin(), piles.end(), compare);
        int sum = 0;
        for (int i = 1; i < 2 * n; i += 2) {
            sum += piles[i];
        }
        return sum;
    }
};

