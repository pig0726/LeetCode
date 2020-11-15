const int S = 243; // 状态数3^5
const int N = 6;  // 行数
const int M = 7; // 人数

int f[N][S][M][M];
// f[i][s][c1][c2]: 已经放置了前 i 行，且第i行的状态是s，已经用掉了 c1 个内向人，c2 个外向人的最大收益
// 答案就是 f 的最大值

// 记录每个状态下，用掉的内向人，外向人的数量
// smap[i].first  s 状态用掉的内向人数量
// smap[i].second  s 状态用掉的外向人数量
using pii = pair<int, int>;
pii smap[S];

// 保持每种状态的三进制表示
// bmap[11] = {1, 0, 2}
vector<int> bmap[S];

// 相邻两个状态下，能新增的收益
// 上一行的状态是 s0
// 当前新加入的行，状态是 s1
// 加入后，会使得总的收益增加多少？
// delta[s0][s1]
int delta[S][S];

class Solution {
public:    
    int getMaxGridHappiness(int n, int m, int IC, int EC) {
        // n 行数，m 列数
        
        // 总状态：3 ^ m
        int limit = 1;
        for (int i = 0; i < m; i++) limit *= 3;
        
        for (int s = 0; s < limit; s++) {
            int tmp = s;
            vector<int> b(m); // s 的三进制表示
            int cnt[3]{0, 0, 0}; // s 状态下，没放人，放内向人，放外向人的数量
            
            // %3 /3 把 s 转成 三进制表示
            for (int i = 0; i < m; i++) {
                b[i] = tmp % 3;
                cnt[tmp % 3]++;
                tmp /= 3;
            }
            
            smap[s].first = cnt[1];
            smap[s].second = cnt[2];
            bmap[s] = b;
        }
        
        // 初始化 delta
        for (int s0 = 0; s0 < limit; s0++)
            for (int s1 = 0; s1 < limit; s1++) {
                const auto& b0 = bmap[s0];
                const auto& b1 = bmap[s1];
                int sum = 0; // 带来的收益
                for (int i = 0; i < m; i++) {
                    if (b1[i] == 0) continue;
                    if (b1[i] == 1) {
                        // 放了内向人
                        sum += 120;
                        // 左边是否有人
                        if (i && b1[i-1] != 0) sum -= 30;
                        // 右边是否有人
                        if (i != m-1 && b1[i+1] != 0) sum -= 30;
                        
                        // 上边是否有人
                        if (b0[i] != 0) sum -= 30;
                        // 上边有内向人，上边的人也减去 30
                        if (b0[i] == 1) sum -= 30;
                        // 上边有外向人，上边的人加上 20
                        if (b0[i] == 2) sum += 20;
                    } else {
                        sum += 40;
                        if (i && b1[i-1] != 0) sum += 20;
                        if (i != m-1 && b1[i+1] != 0) sum += 20;
                        if (b0[i]) sum += 20;
                        if (b0[i] == 1) sum -= 30;
                        if (b0[i] == 2) sum += 20;
                    }
                }
                delta[s0][s1] = sum;
            }
        
        int ret = 0;
        memset(f, -1, sizeof f);
        for (int s = 0; s < limit; s++) {
            int c1 = smap[s].first;
            int c2 = smap[s].second;
            
            if (c1 > IC || c2 > EC) continue;
            
            // s0 上一行，没有上一行，s0 = 0
            // 当前行状态是 s，新增的收益， delta[0][s]
            f[0][s][c1][c2] = delta[0][s];
            ret = max(ret, f[0][s][c1][c2]);
        }
        
        for (int i = 0; i < n-1; i++)
            for (int s0 = 0; s0 < limit; s0++)
                for (int c1 = 0; c1 <= IC; c1++)
                    for (int c2 = 0; c2 <= EC; c2++) {
                        if (f[i][s0][c1][c2] == -1) continue;
                        
                        // 枚举下一行的状态
                        for (int s1 = 0; s1 < limit; s1++) {
                            int newc1 = c1 + smap[s1].first;
                            int newc2 = c2 + smap[s1].second;
                            if (newc1 > IC || newc2 > EC) continue;
                            
                            f[i+1][s1][newc1][newc2] = max(
                                f[i+1][s1][newc1][newc2], f[i][s0][c1][c2] + delta[s0][s1]);
                            ret = max(ret, f[i+1][s1][newc1][newc2]);
                        }
                    }
        return ret;
    }
};
