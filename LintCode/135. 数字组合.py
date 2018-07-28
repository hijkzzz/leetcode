class Solution:
    """
    @param candidates: A list of integers
    @param target: An integer
    @return: A list of lists of integers
    """
    def combinationSum(self, candidates, target):
        # write your code here
        cur = []
        result = []
        self.dfs(candidates, target, cur, result)
        return result
    
    
    def dfs(self, candidates, target, cur, result):
        if target == 0:
            sorted_list = sorted(cur)
            if sorted_list not in result:
                result.append(sorted_list)
            return
        
        for i in range(len(candidates)):
            if candidates[i] <= target:
                cur.append(candidates[i])
                self.dfs(candidates, target - candidates[i], cur, result)
                cur.pop()