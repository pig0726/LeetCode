class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)  return 0;

        vector<int> prime;
        for (int x = 2; x<n; x++) {
            bool isPrime = true;
            for (auto& primeNum : prime) {
                if (x % primeNum == 0) {
                    isPrime = false;
                    break;
                }
                
                if (primeNum*primeNum > x)
                    break;
            }
            if (isPrime)
                prime.push_back(x);        
        }
        return prime.size();
    }
};
