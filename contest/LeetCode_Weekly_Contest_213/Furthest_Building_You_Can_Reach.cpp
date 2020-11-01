using pii = pair<int, int>;
class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int ln) {
        vector<pii> jps;
        int n = h.size();
        
        vector<pii> data;
        for (int i = 0; i < n-1; i++) if (h[i] <= h[i+1]) {
            pii e = make_pair(h[i+1] - h[i], i);
            data.push_back(e);
        }
        
        int m = data.size();
        if (!m) return n-1;
        
        int ans = -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long bigsum = 0;
        long long sum = 0;
        
        for (int i = 0; i < m; i++) {
            sum += data[i].first;
            if (pq.size() < ln) {
                pq.push(data[i].first);
                bigsum += data[i].first;
            } else if (ln > 0) {
                int val = pq.top();
                if (data[i].first > val) {
                    pq.pop();
                    bigsum -= val;
                    pq.push(data[i].first);
                    bigsum += data[i].first;
                }
            }
            
            if (sum - bigsum <= b) {
                ans = data[i].second;  
            } else {
                break;
            }
        }

        int ret = 0;
        for (int i = 0; i < n-1; i++) {
            if (h[i] >= h[i+1]) {
                ret++;
            } else {
                if (i <= ans) ret++;
                else break;
            }
        }
        return ret;
    }
};
