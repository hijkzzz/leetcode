class Solution:
    """
    @param nums: A set of numbers
    @return: A list of lists

    关键在于去重和排序
    """
    def subsets(self, nums):
        # write your code here
        r = []
        cur = []
        self.dfs(sorted(list(nums)), 0, cur, r)
        return r
        
    def dfs(self, nums, start, cur, r):
        if start == len(nums):
            r.append(cur[:])
            return
        
        self.dfs(nums, start + 1, cur ,r)
        
        cur.append(nums[start])
        self.dfs(nums, start + 1, cur ,r)
        cur.pop()