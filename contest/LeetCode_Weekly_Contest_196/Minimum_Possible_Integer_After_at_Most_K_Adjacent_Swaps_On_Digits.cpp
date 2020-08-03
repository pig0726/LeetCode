class Solution {
public:
    inline int lowbit(int x) { return (x&(-x)); }
    
    using pii = pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
    
    vector<bool> vis;
    vector<int> c;
    
    void update(int pos, int n) {
        vis[pos] = false;
        while (pos <= n) {
            --c[pos];
            pos += lowbit(pos);
        }
    }
    
    int get(int pos) {
        int ret = 0;
        for (; pos; pos -= lowbit(pos))
            ret += c[pos];
        return ret;
    }
    
    string minInteger(string num, int k) {
        string ret = num;
        
        int n = num.length();
        for (int i = 0; i < n; ++i) {
          pq.push(make_pair(num[i]-'0', i+1));
        }
        
        vis.assign(n+1, true);
        c.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) 
            c[i] = lowbit(i);
           
        int i = 0;
        for (i = 0; i < n && k; ++i) {
          bool flag = false;
          vector<pii> tmp;
          while (!pq.empty()) {
            pii e = pq.top();
            pq.pop();
            
            int sum = get(e.second) - 1;
            // printf("pop: %d, %d, %d\n", e.first, e.second, sum);
            if (k >= sum) {
                flag = true;
                k -= sum;
                ret[i] = e.first + '0';
                update(e.second, n);
                break;
            } else {
                tmp.push_back(e);
            }
          }
          if (!flag) break;
          for (const auto& e : tmp) pq.push(e);
        }
        
        
        for (int j = 1; j <= n; ++j) if (vis[j])
            ret[i++] = num[j-1];
        
        return ret;
    }
};

