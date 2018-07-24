class Solution:
    """
    @param nums: The integer array.
    @param target: Target to find.
    @return: The first position of target. Position starts from 0.
    """
    def binarySearch(self, nums, target):
        # write your code here
        i = 0
        j = len(nums) - 1
        
        while i <= j:
            m = (i + j ) // 2
            if nums[m] == target and (m == 0 or nums[m - 1] != target):
                return m
            elif nums[m] < target:
                i = m + 1
            else:
                j = m - 1
                
        return -1