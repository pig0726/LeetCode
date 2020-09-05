## A

1. 将对角线的元素都加上
2. 当 n 为奇数时，正中心的元素 mat(n/2, n/2) 被加了两次要减去一次

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += mat[i][i] + mat[i][n-1-i];
        
        if (n & 1) sum -= mat[n/2][n/2];
        return sum;
    }
};
```



## B

1. 当 1 的数量不能被 3 整除时，不能达到题目的要求，答案是 0

2. 当 1 的数量为 0 时，即整个数组所有元素都是 0，那么将 n 个 0 分为 3 份的方案数为：1 * (1 + n-2) * (n - 2) / 2

3. 当 1 的数量能被 3 整除时，我们把所有 1 划分为 3 份。为了方便描述：

   - 把第一份的最后那个 1 的下标称为 A
   - 把第二份的第一个 1 的下标称为 B
   - 把第二份的最后那个 1 的下标称为 C
   - 把第三份的第一个 1 的下标称为 D：

   - A 和 B 之间都是 0，假设数量为 mAB，这些 0 可以归属到第一份或第二份，有 mAB+1 种划分数
   - 同理，C 和 D 之间的 0 的数量为 mCD，能归属到第二份或第三份，有 mCD+1 种划分数
   - 答案为 (mAB+1) * (mCD + 1)

   ```cpp
   class Solution {
   public:
       int numWays(string s) {
           long long MOD = 1e9 + 7;
           vector<int> one;
           int n = s.length();
           for (int i = 0; i < n; ++i)
               if (s[i] == '1') one.push_back(i);
           
           int m = one.size();
           if (!m) {
               return 1LL * (1 + n-2) * (n-2) / 2 % MOD;
           }
           if (m % 3 != 0) return 0;
           int len = m / 3;
           
           int cnt0 = one[len] - one[len-1];
           int cnt1 = one[2*len] - one[2*len-1];
           long long ret = (1LL * cnt0 * cnt1) % MOD;
           return ret;
       }
   };
   ```

   

## C

- 将原数组 A 划分为 m 份：b0，b1，b2 ... bm-1，并且 b0 + b1 +b2 ... + bm-1 = A
- 每一份都是一个非递减序列。
- 当 m = 1 时，原数组就是一个非递减序列，不需要任何删减，答案为 0
- 当 m > 1 时，只能：
  - 保留第一份  b0
  - 保留最后一份 bm-1
  - 保留第一份 b0 的前缀以及最后一份 bm-1 的后缀
- 对于 **保留第一份 b0 的前缀以及最后一份 bm-1 的后缀** 的情况，我们可以枚举 b0 中的元素 x，然后使用二分查找在 bm-1 中找到第一个大于等于x 的元素 y，将原数组 A 的 [x+1, y-1] 区间删除

```cpp
class Solution {
public:
    int find(vector<int>& arr, int t, int st, int ed) {
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) >> 1;
            if (arr[mid] >= t) {
                ans = mid;
                ed = mid - 1;
            } else st = mid + 1;
        }
        return ans;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        using pii = pair<int, int>;
        vector<pii> segs;
        int l = 0, r = 0, n = arr.size();
        while (r < n) {
            if (r == l || arr[r] >= arr[r-1]) ++r;
            else {
                segs.push_back(make_pair(l, r-1));
                l = r;
            }
        }
        segs.push_back(make_pair(l, n-1));
        
        if (segs.size() <= 1) return 0;
        int len0 = segs.front().second - segs.front().first + 1;
        int len1 = segs.back().second - segs.back().first + 1;
        int ret = min(n - len0, n - len1);
        int st = 0, ed = segs[0].second;
        for (int i = st; i <= ed; ++i) {
            int target = arr[i];
            int idx = find(arr, target, segs.back().first, segs.back().second);
            if (idx != -1) {
                ret = min(ret, n - (i + 1 + n - idx));
            }
        }
        return ret;
    }
};
```



## D

- 设 f(i, fuel) 表示当前在第 i 个城市，剩下 fuel 的油量，去到目标城市的方案数
- 只要满足 `i != j && abs(locations[i] - localtions[j]) <= fuel`，则可以从城市 i 去到 城市 j，油量变为 `fuel - abs(locations[i] - localtions[j]) `

```cpp
const int N = 105;
const int F = 205;
const long long MOD = 1e9 + 7;

int f[N][F];
int vis[N][F];

class Solution {
public:
    vector<int> ls;
    int fns, n;
    
    void dfs(int p, int fuel) {
        if (vis[p][fuel]) return;
        vis[p][fuel] = 1;
         
        if (p == fns) f[p][fuel] = 1;
        
        for (int i = 0; i < n; ++i) if (i != p && abs(ls[p] - ls[i]) <= fuel) {
            int re = fuel - abs(ls[p] - ls[i]);
            dfs(i, re);
            f[p][fuel] += f[i][re];
            f[p][fuel] %= MOD;
        }
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        ls = locations;
        fns = finish;
        n = locations.size();
        memset(f, 0, sizeof f);
        memset(vis, 0, sizeof vis);
        dfs(start, fuel);
        return f[start][fuel];
    }
};
```


