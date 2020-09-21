class Solution {
public:
    int subtractProductAndSum(int n) {
        long product = (n == 0 ? 0 : 1);
        long sum = 0;
        while (n) {
            sum += (n % 10);
            product *= (n % 10);
            n /= 10;
        }
        return product - sum;
    }
};
