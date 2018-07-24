class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        # 可以用二分查找加速
        for i in range(len(matrix)):
            if matrix[i][-1] >= target:
                break
        
        if i == len(matrix):
            return False
        
        row = matrix[i]
        for j in range(len(row)):
            if row[j] == target:
                return True
                
        return False