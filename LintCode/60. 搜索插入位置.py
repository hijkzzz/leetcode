class Solution:
    """
    @param A: an integer sorted array
    @param target: an integer to be inserted
    @return: An integer
    """
    def searchInsert(self, A, target):
        # write your code here
        i = 0
        j = len(A) - 1
        while i <= j:
            m = (i + j) // 2
            if A[m] == target:
                return m
            elif A[m] > target:
                if A[m - 1] < target:
                    return m
                else:
                    j = m - 1
            else:
                i = m + 1
        return i