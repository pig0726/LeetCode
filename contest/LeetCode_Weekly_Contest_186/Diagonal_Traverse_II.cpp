class Solution {
public:
    using pii = pair<int, int>;
    struct Elem {int r, c, v;};

    map<pii, vector<Elem> > data;
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), m = 0;
        for (const auto& v : nums) m = max(m, (int)v.size());

        for (int i = 0; i < n; ++i) {
            int len = nums[i].size();
            for (int j = 0; j < len; ++j) {
                int t = i + j + 2;
                int r = -1, c = -1;
                if (t <= n+1) r = t-1, c = 1;
                else r = n, c = t - r;
                Elem e{i, j, nums[i][j]};
                pii pos = make_pair(r, c);
                data[pos].push_back(e);
            }
        }
        vector<int> ret;
        for (int r = 1; r <= n; ++r) {
            int ed = r == n ? m : 1;

            for (int c = 1; c <= ed; ++c) {
                pii p = make_pair(r, c);
                auto it = data.find(p);
                if (it == data.end()) continue;
                sort(it->second.begin(), it->second.end(), [](const Elem& a, const Elem& b) {
                    if (a.r > b.r) return true;
                    else if (a.r < b.r) return false;
                    else return a.c < b.c;
                });
                for (const auto& val : it->second) {
                    ret.push_back(val.v);
                }
            }
        }
        return ret;
    }
};
