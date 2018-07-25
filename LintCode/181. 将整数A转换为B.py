class Solution:
    """
    @param a: An integer
    @param b: An integer
    @return: An integer
    """
    def bitSwapRequired(self, a, b):
        # write your code here
        r = a ^ b
        count = 0
        
        for i in range(32):
            if r & 1:
                count += 1
            r >>= 1
            
        return count