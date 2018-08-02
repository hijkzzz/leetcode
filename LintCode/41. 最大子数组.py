class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        if len(nums) == 0:
            return 0
        
        summ = nums[0] # 当前子数组和
        maxx = nums[0] # 最大子数组和
        
        for i in range(1, len(nums)):
            # 小于等于0时重新开始一个子数组
            if summ <= 0:
                summ = nums[i]
            else:
                summ += nums[i]
                
            maxx = max(summ, maxx)
                
        return maxx