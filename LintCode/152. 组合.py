class Solution:
    """
    @param n: Given the range of numbers
    @param k: Given the numbers of combinations
    @return: All the combinations of k numbers out of 1..n
    """
    def combine(self, n, k):
        # write your code here
        r = []
        cur = []
        self.dfs(1, n, k, cur, r)
        return r

    def dfs(self, s, n, k, cur, r):
        if len(cur) == k:
            r.append(cur[:])
            return
        
        for i in range(s, n + 1):
            cur.append(i)
            self.dfs(i + 1, n, k, cur, r)
            cur.pop()