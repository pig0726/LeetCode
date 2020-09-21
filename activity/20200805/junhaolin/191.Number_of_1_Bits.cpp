class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for(int i=0; i<32; i++) {
            result += (0x01 & n);
            n = n >> 1;
        }
        return result;
    }
};
