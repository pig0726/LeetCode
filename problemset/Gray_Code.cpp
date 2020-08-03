class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) ret[i] = i ^ (i >> 1);
        return ret;
     }
};
