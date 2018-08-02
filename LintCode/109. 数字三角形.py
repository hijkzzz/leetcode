class Solution:
    """
    @param triangle: a list of lists of integers
    @return: An integer, minimum path sum
    """
    def minimumTotal(self, triangle):
        # write your code here
        if len(triangle) == 0 or len(triangle[0]) == 0:
            return 0
        
        n = len(triangle)
        
        dp = [[float('inf') for j in range(n) ]for i in range(n)]
        dp[0][0] = triangle[0][0]
        
        for i in range(1, n):
            for j in range(i + 1):
                if j == 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
                    
        return min(dp[n - 1])
