class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxval = 0;
        for (int a : arr) maxval = max(a, maxval);
        
        int l = 0, r = l+1, n = arr.size();
        while (arr[l] != maxval) {            
            if (arr[r] < arr[l]) ++r;
            else {
                int cnt = 0;
                if (l == 0) cnt = r - l - 1;
                else cnt = r - l;
                if (cnt >= k) return arr[l];
                l = r;
                r = l+1;
            }
        }
        return maxval;
    }
};
