class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.size() == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }

        int low = 0, hight = nums.size()-1;
        int index1 = -1, index2 = -1;
        while (low <= hight) {
            int mid = (low + hight) >> 1;
            int value = nums[mid];
            if (value < target) {
                low = mid + 1;
            } else if (value == target) {
                index1 = mid;
                hight = mid - 1;
            } else {
                hight = mid - 1;
            }
        }

        if (index1 == -1) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }

        low = 0, hight = nums.size()-1;
        while (low <= hight) {
            int mid = (low + hight) >> 1;
            int value = nums[mid];
            if (value < target) {
                low = mid + 1;
            } else if (value == target) {
                index2 = mid;
                low = mid + 1;
            } else {
                hight = mid - 1;
            }
        }

        ret.push_back(index1);
        ret.push_back(index2);

        return ret;
    }
};
