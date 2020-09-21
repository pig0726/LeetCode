const int N = 5000005;
char buf[N];
int length;

class Solution {
public:
    void add(char* buf, int w, int s, int e) {
        for (int i = e-1; i >= s; --i) {
            int x = buf[i] - '0';
            buf[w++] = '0' + 1 - x;
        }
    }
    char findKthBit(int n, int k) {
        n--;
        k--;
        buf[0] = '0';
        length = 1;
        
        for (int i = 1; i <= n; ++i) {
            int len = length;
            buf[length++] = '1';
            add(buf, length, 0, len);
            length += len;
        }
        
        return buf[k];
    }
};
