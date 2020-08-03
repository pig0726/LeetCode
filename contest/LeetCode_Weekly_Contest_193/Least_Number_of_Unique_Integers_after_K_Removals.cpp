class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> data;
        for (int x : arr) data[x] += 1;
        
        using pii = pair<int, int>;
        vector<pii> a;
        for (const auto& p : data) 
            a.push_back(make_pair(p.second, p.first));
        sort(a.begin(), a.end());
        
        int i = 0;
        for (; i < a.size() && k >= a[i].first; ++i) {
            k -= a[i].first;
        }
        
        int re = a.size() - i;
        return re;
    }
};
