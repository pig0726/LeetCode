class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int ret = 0;
        while (k--) {
            ret = pq.top();
            pq.pop();
        }
        return ret;
    }
};
