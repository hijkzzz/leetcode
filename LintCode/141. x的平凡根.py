class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        i = 0
        j = x
        while i <= j:
            m = (i + j) // 2
            p = m * m
            
            if p == x:
                return m
            elif p > x:
                j = m - 1
            else:
                i = m + 1
        return i - 1 if i * i > x else i