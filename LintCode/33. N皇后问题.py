class Solution:
    """
    @param: n: The number of queens
    @return: All distinct solutions
    """
    def solveNQueens(self, n):
        # write your code here
        r = []
        pos = [0 for i in range(n)]
        self.dfs(pos, 0, n, r)
        return r
        
    def dfs(self, pos, i, n, r):
        if i == n:
            r.append(self.output(pos))
            return
        
        for j in range(n):
            if self.check(pos, i, j):
                pos[i] = j
                self.dfs(pos, i + 1, n, r)
                
    def check(self, pos, i, j):
        for k in range(i):
            if pos[k] == j:
                return False
            if i + j == k + pos[k] or i - j == k - pos[k]:
                return False
        return True
    
    def output(self, pos):
        r = []
        n = len(pos)
        for i in range(n):
            j = pos[i]
            s = '.' * j + 'Q' + '.' * (n - j - 1)
            r.append(s)
            
        return r