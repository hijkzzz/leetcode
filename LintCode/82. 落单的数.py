class Solution:
    """
    @param A: An integer array
    @return: An integer
    """
    def singleNumber(self, A):
        # write your code here
        start = A[0]
        for i in range(1, len(A)):
            start ^= A[i]
        return start