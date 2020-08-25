class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> cnt(n);
        int st = rounds.front() - 1;
        int m = rounds.size();
        int rd = 0;
        while (rd < m-1) {
            cnt[st]++;
            if (st+1 == rounds[rd+1]) {
                rd++;
            }
            st = (st + 1) % n;
        }
        
        int maxc = 0;
        for (int a : cnt) maxc = max(maxc, a);
        
        vector<int> data;
        for (int i = 0; i < n; ++i) if (cnt[i] == maxc) {
            data.push_back(i+1);
        }
        return data;
    }
};
