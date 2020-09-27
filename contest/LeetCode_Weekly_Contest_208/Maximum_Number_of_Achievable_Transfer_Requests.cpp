class Solution {
public:
    vector<int> io;
    int maxReq = 0;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int res = 0;
        for (auto it = requests.begin(); it != requests.end();) {
            if ((*it)[0] == (*it)[1]) {
                it = requests.erase(it);
                res++;
            }  
            else it++;
        }
        io.resize(n, 0);
        dfs(0, 0, n, requests);
        return maxReq + res;
    }

    void dfs(int i, int curr, int n, vector<vector<int>>& requests) {
        if (i == requests.size()) {
            int res = curr;
            int flag = true;
            for (int k = 0; k < n; k++) {
                if (io[k] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag && res > maxReq) {
                maxReq = res;
            }
            return;
        }
        if (curr + requests.size() - i + 1 <= maxReq) return;
        auto request = requests[i];
        io[request[0]]--;
        io[request[1]]++; 
        dfs(i + 1, curr + 1, n, requests);
        io[request[0]]++;
        io[request[1]]--;
        dfs(i + 1, curr, n, requests);
    }
};

