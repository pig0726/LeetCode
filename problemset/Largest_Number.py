class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        return str(long("".join(sorted(map(str, nums), cmp = lambda x, y: cmp(y+x, x+y)))))
