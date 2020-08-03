class Solution {
public:
    
    bool check(const vector<string>& a, const vector<string>& b) {
        int n = a.size(), m = b.size();
        int cnt = 0, pa = 0, pb = 0;
        while (pa < n && pb < m) {
            if (a[pa] == b[pb]) {
                cnt++;
                pa++;
                pb++;
            } else if (a[pa] < b[pb]) pa++;
            else pb++;
        }
        return cnt == n;
    }
    vector<int> peopleIndexes(vector<vector<string>>& FC) {
        using pvi = pair<vector<string>, int>;
        
        vector<pvi> data;
        
        int n = FC.size();
        for (int i = 0; i < n; ++i) {
            sort(FC[i].begin(), FC[i].end());
            data.push_back(make_pair(FC[i], i));
        }
        sort(data.begin(), data.end(), [](const pvi& a, const pvi& b) {
            if (a.first.size() != b.first.size()) return a.first.size() < b.first.size();
            return a.first < b.first;
        });
        
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            int flag = true;
            for (int j = i+1; j < n; ++j)
                if (check(data[i].first, data[j].first)) { 
                    flag = false;
                    break; 
                }
            if (flag) ret.push_back(data[i].second);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
