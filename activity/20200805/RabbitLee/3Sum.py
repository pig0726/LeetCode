class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = []
        nums = sorted(nums)
        
        first = 0
        while first < len(nums) - 2:
            twins = self.twoSum2(nums[first + 1:], -nums[first])
            triplets += [[nums[first]] + twin for twin in twins]
            first += 1
            while first < len(nums) - 2 and nums[first] == nums[first - 1]:
                first += 1
                
        return triplets
    
    def twoSum2(self, numbers: List[int], target: int) -> List[List[int]]:
        twins = list()
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            if numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                twins.append([numbers[left], numbers[right]])
                right -= 1
                left += 1
                while left < right and numbers[left] == numbers[left - 1]:
                    left += 1
                    
        return twins           

