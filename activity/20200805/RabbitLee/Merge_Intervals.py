class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 1:
            return []
        intervals = sorted(intervals, key=lambda interval: (interval[0], interval[1]))
        ans = []
        cur_interval = intervals[0]
        for i in range(1, len(intervals)):
            interval = intervals[i]
            if cur_interval[1] < interval[0]:
                ans.append(cur_interval)
                cur_interval = interval
            else:
                cur_interval[1] = max(cur_interval[1], interval[1])
         
        ans.append(cur_interval)
        return ans

