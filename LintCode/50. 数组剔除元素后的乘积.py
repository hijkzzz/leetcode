class Solution:
    """
    @param: nums: Given an integers array A
    @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, nums):
        if len(nums) < 2:
            return [1]
        
        # write your code here
        left = nums[:]
        right = nums[:]
        
        for i in range(1, len(nums)):
            left[i] *= left[i - 1]
            right[len(nums) - i - 1] *= right[len(nums) - i] 
            
        B = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            if i == 0:
                B[i] = right[i + 1]
            elif i == len(nums) - 1:
                B[i] = left[i - 1]
            else:
                B[i] = left[i - 1] * right[i + 1]
        return B