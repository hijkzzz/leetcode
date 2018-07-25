class Solution:
    """
    @param nums: a rotated sorted array
    @return: the minimum number in the array
    """
    def findMin(self, nums):
        # write your code here
        i = 0
        j = len(nums) - 1
        
        # 当使用 i = m 或者 j = m 时要分析下边界情况
        while i < j:
            m = (i + j) // 2
            if nums[m] > nums[j]:
                i = m + 1
            else:
                j = m
        
        return nums[i]