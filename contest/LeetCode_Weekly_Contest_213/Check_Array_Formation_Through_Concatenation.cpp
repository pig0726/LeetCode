class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool ret = true;
        int idx = 0;
        int n = arr.size();
        int m = pieces.size();
        vector<bool> vis(m, false);
        
        while (idx < n) {
            bool found = false;
            for (int i = 0; i < m; i++) if (!vis[i] && pieces[i].front() == arr[idx]) {
                int K = pieces[i].size();
                if (K > n - idx) return false;
                for (int k = 0; k < K; k++) 
                    if (pieces[i][k] != arr[idx+k]) return false;
                idx += K;
                vis[i] = true;
                found = true;
            } 
            if (!found) return false;
        }
        return ret;
    }
};
