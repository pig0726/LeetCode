using pii = pair<int, int>;
const int dr[4]{0, -1, 0, 1};
const int dc[4]{-1, 0, 1, 0};

class Solution {
public:
    static inline const int N = 10005;
    int dp[N];
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for (int i = 0; i < N; i++) dp[i] = 1e9;
        
        int n = heights.size();
        int m = heights.front().size();
        dp[0] = 0;
        pq.push(make_pair(0, 0));
        
        while (!pq.empty()) {
            const auto e = pq.top();
            pq.pop();
            int row = e.second / m;
            int col = e.second % m;
            int delta = e.first;
            
            for (int i = 0; i < 4; i++) {
                int r = row + dr[i];
                int c = col + dc[i];
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                int v = abs(heights[row][col] - heights[r][c]);
                int newv = max(v, delta);
                int pos = r * m + c;
                
                if (newv < dp[pos]) {
                    dp[pos] = newv;
                    pq.push(make_pair(newv, pos));
                }
            }
        }
        
        return dp[n*m-1];
    }
};
