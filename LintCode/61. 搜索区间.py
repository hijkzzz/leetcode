class Solution:
    """
    @param A: an integer sorted array
    @param target: an integer to be inserted
    @return: a list of length 2, [index1, index2]
    """
    def searchRange(self, A, target):
        # write your code here
        r = [-1, -1]
        if len(A) == 0:
            return r
        
        i = 0
        j = len(A) - 1
        
        while i <= j:
            m = (i + j) // 2
            if A[m] >= target:
                j = m - 1
            else:
                i = m + 1
        
        if i >= len(A) or A[i] != target:
            return [-1, -1]
        
        r[0] = i
        
        i = 0
        j = len(A) - 1
        
        while i <= j:
            m = (i + j) // 2
            if A[m] <= target:
                i = m + 1
            else:
                j = m - 1
                
        r[1] = j
        
        return r
        