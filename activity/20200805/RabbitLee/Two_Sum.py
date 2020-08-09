class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_set = set()
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in nums_set:
                another_index = nums.index(another_num)
                return [another_index, index]
            nums_set.add(num)

