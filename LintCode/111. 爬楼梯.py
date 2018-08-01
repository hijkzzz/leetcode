class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        if n <= 1:
            return n
        
        prepre = 1
        pre = 2
        current = 2
        
        for i in range(2, n):
            current = prepre + pre
            prepre = pre
            pre = current
            
        return current
