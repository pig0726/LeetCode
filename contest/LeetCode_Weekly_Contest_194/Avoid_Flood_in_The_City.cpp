class Solution {
public:
    std::map<int, int> lakes;
    std::set<int> days;
    
    int getd(int limit) {
        auto it = days.upper_bound(limit);
        if (it == days.end()) return -1;
        return *it;
    }
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ret(n, -1);
        
        for (int i = 0; i< n; ++i) {
            if (rains[i] > 0) {
                ret[i] = -1;
                auto it = lakes.find(rains[i]);
                if (it == lakes.end()) {
                    lakes[rains[i]] = i;
                } else {
                    if (days.empty()) return {};
                    int d = getd(it->second);
                    days.erase(d);
                    if (d < it->second) return {};
                    ret[d] = rains[i];
                    lakes[rains[i]] = i;
                }
            } else days.insert(i);
        }
        for (int d : days) ret[d] = 1;
        return ret;
    }
};
