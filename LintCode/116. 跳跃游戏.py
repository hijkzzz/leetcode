class Solution:
    """
    @param A: A list of integers
    @return: A boolean

    要充分考虑边界情况
    """
    def canJump(self, A):
        # write your code here
        current_pos = 0
        
        while current_pos < len(A) - 1:
            if A[current_pos] == 0:
                return False
                
            # 当前点能跳的最远位置
            max_pos = current_pos + A[current_pos]  
            if max_pos >= len(A) - 1:
                return True
            
            # 选择能跳的最远的点作为下一个位置
            for i in range(current_pos + 1, max_pos + 1):
                if i + A[i] >= max_pos:
                    max_pos = i + A[i]
                    current_pos = i
        
        return True