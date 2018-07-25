class Solution:
    """
    @param: A: An integers array.
    @return: return any of peek positions.
    
    https://blog.csdn.net/cinderella_niu/article/details/43056759
    """
    def findPeak(self, A):
        # write your code here
        i = 1
        j = len(A) - 2
        
        while i < j:
            m = (i + j) // 2
            
            if A[m] < A[m + 1]:
                i = m + 1
            elif A[m] > A[m + 1]:
                j = m
        
        return i