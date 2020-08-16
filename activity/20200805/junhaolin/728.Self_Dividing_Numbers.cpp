class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i=left; i<=right; i++) {
            int n = i;
            while (n) {
                if (n % 10 == 0)
                    break;
                else if (i % (n%10) != 0)
                    break;
                
                n /= 10;
            }
            
            if(n == 0)
                result.push_back(i);
        }
        return result;
    }
};
