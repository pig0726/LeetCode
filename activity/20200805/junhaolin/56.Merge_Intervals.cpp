class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), comp);
        
        for(int i=0; i<intervals.size(); i++) {
            if (result.empty()) {
                result.push_back(intervals[i]);
            } else {
                vector<int> back = result.back();
                result.pop_back();
                vector<vector<int>> vv = merge(back, intervals[i]);
                for (int i=0; i<vv.size(); i++)
                    result.push_back(vv[i]);
            }
        }
        return result;
    }
    
    vector<vector<int>> merge(vector<int>& a, vector<int>& b) {
        vector<vector<int>> vv;
        if (b[0] <= a[1]) 
            vv.push_back(vector<int> {a[0], max(a[1],b[1])});
        else {
            vv.push_back(a);
            vv.push_back(b);
        }
        return vv;
    }
    
    static bool comp(vector<int> & a, vector<int> & b) {
        return (a[0]<b[0]) || (a[0]==b[0] && a[1]<b[1]);
    }
};
