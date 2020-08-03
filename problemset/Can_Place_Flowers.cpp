class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) continue;
            int cnt = 2;
            if (i == 0 || flowerbed[i-1] == 0) cnt--;
            if (i == flowerbed.size()-1 || flowerbed[i+1] == 0) cnt--;
            if (!cnt) {
                ans++;
                flowerbed[i] = 1;
            }
        }
        return ans >= n;
    }
};
