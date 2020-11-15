const int S = 243;
const int N = 10;
const int M = 10;
int f[N][S][M][M];
int delta[S][S];
using pii = pair<int, int>;
pii smap[S];
vector<int> bmap[S];

class Solution {
public:    
    int getMaxGridHappiness(int n, int m, int ic, int ec) {
        int limit = 1;
        for (int i = 0; i < m; i++) limit *= 3;
        
        for (int i = 0; i < limit; i++) {
            int s = i;
            int c[3]{0, 0, 0};
            vector<int> b(m);
            for (int k = 0; k < m; k++) {
                b[k] = s % 3;
                c[s % 3]++;
                s /= 3;
            }
            smap[i] = {c[1], c[2]};
            bmap[i] = b;
        }
        
        for (int s0 = 0; s0 < limit; s0++) {
            for (int s1 = 0; s1 < limit; s1++) {
                const auto& b0 = bmap[s0];
                const auto& b1 = bmap[s1];
                
                int sum = 0;
                for (int i = 0; i < m; i++) {
                    if (b1[i] == 1) {
                        sum += 120;
                        if (i && b1[i-1] != 0) sum -= 30;
                        if (i != m-1 && b1[i+1] != 0) sum -= 30;
                        if (b0[i] != 0) sum -= 30;
                        if (b0[i] == 1) sum -= 30;
                        if (b0[i] == 2) sum += 20;
                    } else if (b1[i] == 2) {
                        sum += 40; 
                        if (i && b1[i-1] != 0) sum += 20;
                        if (i != m-1 && b1[i+1] != 0) sum += 20;
                        if (b0[i] != 0) sum += 20;
                        if (b0[i] == 1) sum -= 30;
                        if (b0[i] == 2) sum += 20;
                    }
                }
                delta[s0][s1] = sum;
            }
        }
        
        
        int ret = 0;
        memset(f, -1, sizeof f);
        for (int i = 0; i < limit; i++) {
            int cnt1 = smap[i].first;
            int cnt2 = smap[i].second;
            if (cnt1 > ic || cnt2 > ec) continue;
            int sum = 0;
            const auto& b = bmap[i];
            for (int k = 0; k < m; k++) {
                if (b[k] == 1) {
                    sum += 120;
                    if (k && b[k-1] != 0) sum -= 30;
                    if (k != m-1 && b[k+1] != 0) sum -= 30;
                } else if (b[k] == 2) {
                    sum += 40;
                    if (k && b[k-1] != 0) sum += 20;
                    if (k != m-1 && b[k+1] != 0) sum += 20;
                }
            }
            f[0][i][cnt1][cnt2] = sum;
            ret = max(ret, f[0][i][cnt1][cnt2]);
        }
        
        
        for (int i = 0; i < n-1; i++) {
            for (int cnt1 = 0; cnt1 <= ic; cnt1++) {
                for (int cnt2 = 0; cnt2 <= ec; cnt2++) {
                    for (int s0 = 0; s0 < limit; s0++) {                        
                        if (f[i][s0][cnt1][cnt2] == -1) continue;
                        
                        for (int s1 = 0; s1 < limit; s1++) {
                            int c1 = smap[s1].first, c2 = smap[s1].second;
                            if (cnt1 + c1 > ic || cnt2 + c2 > ec) continue;
                            int newc1 = cnt1 + c1;
                            int newc2 = cnt2 + c2;
                            f[i+1][s1][newc1][newc2] = 
                                max(f[i+1][s1][newc1][newc2],
                                    f[i][s0][cnt1][cnt2] + delta[s0][s1]);           
                            ret = max(ret, f[i+1][s1][newc1][newc2]);     
                        }
                    }
                }
            }
        }
        
        return ret;
        
    }
};
