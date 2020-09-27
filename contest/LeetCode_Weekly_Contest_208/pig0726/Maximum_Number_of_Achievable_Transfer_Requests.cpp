class Solution {
public:
    int m;
    int n;
    vector<vector<int>> rs;
    
    int check(int s) {
        int cnt = 0;
        vector<int> ind(n, 0);
        vector<int> outd(n, 0);
        
        for (int i = 0; i < m; ++i) if (s & (1<<i)) {
            cnt++;
            int from = rs[i][0], to = rs[i][1];
            outd[from]++;
            ind[to]++;
        }
        
        for (int i = 0; i < n; ++i)
            if (ind[i] != outd[i]) return -1;
        return cnt;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n = n;
        m = requests.size();
        rs = requests;
        int maxstatus = 1<<m;
        
        int maxval = 0;
        for (int i = 1; i < maxstatus; i++) {
            int val = check(i);
            if (val > maxval) maxval = val; 
        }
        return maxval;
    }
};
