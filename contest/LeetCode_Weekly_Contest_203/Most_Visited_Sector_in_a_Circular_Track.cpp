class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds[0], end = rounds.back();
        if (start <= end) {
            return generateVectorOfRange(start, end + 1);
        } else {
            vector<int> a, b;
            a = generateVectorOfRange(1, end + 1);
            b = generateVectorOfRange(start, n + 1);
            a.reserve(a.size() + b.size());
            a.insert(a.end(), b.begin(), b.end());
            return a;
        }
    }
    
    vector<int> generateVectorOfRange(int start, int end) {
        vector<int> res;
        for (int i = start; i < end; i++) {
            res.push_back(i);
        }
        return res;
    }
};

