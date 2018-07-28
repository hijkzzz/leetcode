class Solution:
    """
    @param: :  A list of integers
    @return: A list of unique permutations

    还可以更高效的实现
    """

    def permuteUnique(self, nums):
        # write your code here
        cur = []
        r = []
        self.dfs(nums, cur, len(nums), r)
        return r
        
        
    def dfs(self, nums, cur, n, r):
        if len(cur) == n and cur not in r:
            r.append(cur[:])
            return
        
        for i in range(len(nums)):
            cur.append(nums[i])
            self.dfs(nums[0:i] + nums[i + 1:], cur, n, r)
            cur.pop()