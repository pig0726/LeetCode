class Solution {
public:
    const double EPS = 0.0000001;

    bool judgePoint24(vector<int>& nums) {
        vector<double> x;
        for (int i = 0; i < nums.size(); i++) x.push_back(nums[i]);
        return solve(x);
    }

    bool solve(vector<double>& nums) {
        if (nums.size() == 1) return abs(nums[0]-24.0) < EPS;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                vector<double> x;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    x.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                double v1 = a + b;
                x.push_back(v1);
                if (solve(x)) return true;
                x.pop_back();

                double v2 = a - b;
                x.push_back(v2);
                if (solve(x)) return true;
                x.pop_back();

                double v3 = a * b;
                x.push_back(v3);
                if (solve(x)) return true;
                x.pop_back();

                if (b != 0) {
                    x.push_back(a/b);
                    if (solve(x)) return true;
                    x.pop_back();
                }
            }
        }
        return false;
    }
};
