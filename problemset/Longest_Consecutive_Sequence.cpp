class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table;
        for (int i = 0; i < nums.size(); i++) {
            table.insert(nums[i]);
        }

        int cnt = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(nums[i]) == table.end()) continue;
            table.erase(nums[i]);
            cnt = 1;

            for (int m = nums[i]-1; ; m--) {
                if (table.find(m) == table.end()) {
                    break;
                }
                table.erase(m);
                cnt++;
            }

            for (int m = nums[i] + 1; ; m++) {
                if (table.find(m) == table.end()) {
                    break;
                }
                table.erase(m);
                cnt++;
            }

            ret = max(ret, cnt);
        }
        return ret;
    }
};
