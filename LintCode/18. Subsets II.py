class Solution:
    """
    @param nums: A set of numbers.
    @return: A list of lists. All valid subsets.

    暴力去重
    """
    def subsetsWithDup(self, nums):
        # write your code here
        r = []
        cur = []
        self.dfs(sorted(nums), 0, cur, r)
        return r
        
    def dfs(self, nums, start, cur, r):
        if start == len(nums):
            cur = cur[:]
            if cur not in r:
                r.append(cur)
            return
        
        self.dfs(nums, start + 1, cur ,r)
        
        cur.append(nums[start])
        self.dfs(nums, start + 1, cur ,r)
        cur.pop()
