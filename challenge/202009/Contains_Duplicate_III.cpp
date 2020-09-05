const int N = 20005;
int c[N];

inline int lowbit(int p) {
    return p & (-p);
}

void update(int p, int n, int v) {
    while (p <= n) {
        c[p] += v;
        p += lowbit(p);
    }
} 

int query(int p) {
    int sum = 0;
    while (p) {
        sum += c[p];
        p -= lowbit(p);
    }
    return sum;
}

bool check(int p, int n, int k) {
    int l = max(0, p - k);
    int r = min(n, p + k);
    
    int cnt = query(r);
    if (l > 1) {
        cnt -= query(l-1);
    }
    
    return cnt >= 2;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 0 || k <= 0 || t < 0) return false;
        
        memset(c, 0, sizeof c);
        using pii = pair<int, int>;
        vector<pii> data;
        for (int i = 0; i < n; ++i) {
            data.push_back(make_pair(nums[i], i));
        }
        sort(data.begin(), data.end());
        
        int l = 0, r = 0;
        
        while (true) {
            while(r < n && 0LL + data[r].first - data[l].first <= t + 0LL) {
                update(data[r].second+1, n, 1);
                if (check(data[r].second+1, n, k)) return true;
                r++;
            }
            if (r >= n) break;
            while(l <= r && 0LL + data[r].first - data[l].first > 0LL + t) {
                update(data[l].second+1, n, -1);
                l++;
            }
            if (l >= n) break;
            
        }
        return false;
    }
};