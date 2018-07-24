class Solution:
    """
    @param nums: The integer array you should partition
    @param k: An integer
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        # write your code here
        p = 0
        for i in range(len(nums)):
            if nums[i] < k:
                nums[p], nums[i] = nums[i], nums[p]
                p += 1
                
        return p