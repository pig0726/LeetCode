class Solution {
public:
    bool work(vector<int>& bloomDay, int day, int m, int k) {
        
        int n = bloomDay.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) 
            if (bloomDay[i] <= day) 
                vis[i] = true;
        
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) cnt = 0;
            else {
                cnt++;
                if (cnt == k) {
                    ret++;
                    cnt = 0;
                }
            }
        }
        return ret >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> day = bloomDay;
        sort(day.begin(), day.end());
        auto it = unique(day.begin(), day.end());
        day.erase(it, day.end());
        
        int low = 0, high = day.size() - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            bool ret = work(bloomDay, day[mid], m, k);
            if (ret) ans = day[mid], high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};
