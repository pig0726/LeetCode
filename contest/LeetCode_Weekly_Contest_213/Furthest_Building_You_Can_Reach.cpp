class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int ln) {
        priority_queue<int> pq;
        long long bigsum = 0;
        long long sum = 0;
        int n = h.size();
        for (int i = 1; i < n; i++) {
            if (h[i] <= h[i-1]) continue;
            int d = h[i] - h[i-1];

            if (pq.size() < ln) {
                bigsum += d;
                pq.push(d);
            } else if (ln && pq.top() < d) {
                bigsum -= pq.top();
                pq.pop();
                pq.push(d);
                bigsum += d;
            }
            sum += d;
            if (sum - bigsum > b) return i-1;
        }
        return n-1;
    }
};
