class Solution:
    """
    @param: nums: An ineger array
    @return: An integer
    """
    def removeDuplicates(self, nums):
        # write your code here
        if len(nums) < 2:
            return len(nums)
        
        i = 1
        j = 1
        while j < len(nums):
            if nums[j] != nums[j - 1]:
                nums[i] = nums[j]
                i += 1
            j += 1
            
        return i