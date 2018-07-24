class Solution:
    """
    @param A: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, A, target):
        # write your code here
        i = 0
        j = len(A) - 1
        
        while i <= j:
            m = (i + j) // 2
            if A[m] == target:
                return m
            elif A[m] > A[i]:
                if A[i] <= target and A[m] > target:
                    j = m - 1
                else:
                    i = m + 1
            else:
                if A[m] < target and A[j] >= target:
                    i = m + 1
                else:
                    j = m - 1
        
        return -1