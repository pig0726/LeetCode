class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        using pii = pair<int, int>;
        vector<pii> data;
        sort(arr.begin(), arr.end());
        int midx = (arr.size()-1)/2;
        int mid = arr[midx];
        for (int i = 0; i < arr.size(); ++i) {
            data.push_back(make_pair(abs(arr[i]-mid), arr[i]));
        }
        sort(data.begin(), data.end(), [](const pii& a, const pii& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        });
        
        vector<int> ret;
        for (int i = 0; i < k; ++i) ret.push_back(data[i].second);
        return ret;
    }
};
