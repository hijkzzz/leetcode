class Solution:
    """
    @param A: An array of integers
    @return: An integer
    """
    def firstMissingPositive(self, A):
        # write your code here
        i = 0
        while i < len(A):
            integer = A[i]
            if integer == i + 1:
                i += 1
            elif integer <= len(A) and integer >= 1 and A[integer - 1] != integer:
                A[i], A[integer - 1] = A[integer - 1], A[i]
            else:
                i += 1
        
        for i in range(len(A)):
            if A[i] != i + 1:
                return i + 1
        
        return len(A) + 1