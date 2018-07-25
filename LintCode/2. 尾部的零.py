class Solution:
    """
    @param: n: An integer
    @return: An integer, denote the number of trailing zeros in n!
    """
    def trailingZeros(self, n):
        # write your code here, try to do it without arithmetic operators.
        # n!质因数分解 看看有多少对(2, 5) 即5的个数
        # 可用公式 Z = N/5 + N /(5*5) + N/(5*5*5)... 求解
        
        r = 0
        while n > 0:
            n //= 5
            r += n
        return r