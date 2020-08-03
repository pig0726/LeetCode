const int MAXBIT = 25;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int diff = INT_MAX;
        set<int> data;
        for (int a : arr) {
            set<int> oldd = data;
            data.clear();
            data.insert(a);
            
            for (int v : oldd) {
                data.insert(v & a);
            }
            
            for (int v : data) {
                diff = min(diff, abs(v - target));
            }
        }
        return diff;
    }
};
