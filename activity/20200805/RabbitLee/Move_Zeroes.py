class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        quick, slow = 0, 0
        while quick < len(nums):
            if nums[quick] != 0:
                nums[slow] = nums[quick]
                slow += 1
            quick += 1
        while slow < len(nums):
            nums[slow] = 0
            slow += 1

