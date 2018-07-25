class Solution:
    """
    @param n: An integer
    @return: True or false
    """
    def checkPowerOf2(self, n):
        # write your code here
        if n <= 0:
            return False
            
        # 只有一位是1
        return n & (n - 1) == 0