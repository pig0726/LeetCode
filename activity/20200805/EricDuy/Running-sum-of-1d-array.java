class Solution {
    public int[] runningSum(int[] nums) {
        if(nums.length==1) return nums;
        nums[1] = nums[0] + nums[1];
        for(int i = 2; i < nums.length; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
}
