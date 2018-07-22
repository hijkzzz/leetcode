class Solution:
    """
    @param: A: A list of integers
    @param: elem: An integer
    @return: The new length after remove
    """
    def removeElement(self, A, elem):
        if len(A) == 0:
            return 0
        
        # write your code here
        i = 0
        j = len(A) - 1
        while i < j:
            while A[i] != elem and i < j:
                i += 1
            while A[j] == elem and i < j:
                j -= 1
            
            A[i], A[j] = A[j], A[i]
                
        return j + 1 if A[j] != elem else j