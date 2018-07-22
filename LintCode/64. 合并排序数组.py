class Solution:
    """
    @param: A: sorted integer array A which has m elements, but size of A is m+n
    @param: m: An integer
    @param: B: sorted integer array B which has n elements
    @param: n: An integer
    @return: nothing
    """
    def mergeSortedArray(self, A, m, B, n):
        # write your code here
        r  = []
        i = m - 1
        j = n - 1
        p = m + n - 1
        
        while i >= 0 and j >= 0:
            if A[i] > B[j]:
                A[p] = A[i]
                i -= 1
            else:
                A[p] = B[j]
                j -= 1
            p -= 1

        while i >= 0:
            A[p] = A[i]
            i -= 1
            p -= 1

        while j >= 0:
            A[p] = B[j]
            j -= 1
            p -= 1