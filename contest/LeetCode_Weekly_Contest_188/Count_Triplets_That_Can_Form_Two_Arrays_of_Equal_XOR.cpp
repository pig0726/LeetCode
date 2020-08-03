class Solution {
public:
    int n = 0;
    vector<int> prexorsum;

    int getsum(int L, int R) {
        if (!L) return prexorsum[R];
        return prexorsum[R] ^ prexorsum[L-1];
    }

    int countTriplets(vector<int>& arr) {
        n = arr.size();
        prexorsum.assign(n, 0);

        prexorsum[0] = arr[0];
        for (int i = 1; i < n; ++i)
            prexorsum[i] = prexorsum[i-1] ^ arr[i];

        int ret = 0;
        for(int i = 0; i < n; ++i)
            for (int k = i+1; k < n; ++k) if (getsum(i, k) == 0) {
                for (int j = i+1; j <= k; ++j) if (getsum(i, j-1) == getsum(j, k))
                    ret++;
            }
        return ret;
    }
};