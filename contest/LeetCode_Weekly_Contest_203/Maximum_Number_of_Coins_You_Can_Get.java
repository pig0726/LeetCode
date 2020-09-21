class Solution {
    public int maxCoins(int[] piles) {
        int n = piles.length / 3;
        Arrays.sort(piles);
        int sum = 0;
        for (int i = 3 * n - 2; i >= n; i -= 2) {
            sum += piles[i];
        }
        return sum;
    }
}

