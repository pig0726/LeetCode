class Solution {
public:
    using pii = pair<int, int>;
    using ll = long long;
    priority_queue<pii> pq;
    
    int maxProfit(vector<int>& iy, int orders) {
        unordered_map<int, int> tmp;
        for (int cnt : iy) tmp[cnt]++;
        for (const auto p : tmp) pq.push(p);
        
        long long ret = 0;
        int mod = 1e9 + 7;
        
        while (orders > 0 && !pq.empty()) {
            pii p = pq.top();
            pq.pop();
            
            long long delta = 0;
            if (pq.empty()) {
                delta = p.first;
            } else {
                pii p2 = pq.top();
                pq.pop();
                delta = p.first - p2.first;
                p2.second += p.second;
                pq.push(p2);
            }
            
            ll num = 1LL * delta * p.second;
            int cnt, ed, st, flag;
            if (1LL * orders > num) {
                cnt = delta;
                flag = false;
            } else {
                cnt = orders / p.second;
                flag = true;
            }
            
            ed = p.first;
            st = p.first - cnt + 1;
            
            ll val = (1LL * (st + ed) * cnt / 2) % mod;
            val = (val * p.second) % mod;
            ret = (ret + val) % mod;
            
            orders -= cnt * p.second;
            
            if (flag && orders) {
                int v = st - 1;
                ret = (ret + 1LL * v * orders) % mod;
                orders = 0;
            }
        }
        return ret;
    }
};
