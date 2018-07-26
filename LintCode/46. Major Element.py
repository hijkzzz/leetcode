class Solution:
    """
    @param: nums: a list of integers
    @return: find a  majority number

    采用抵消的思想
    """
    def majorityNumber(self, nums):
        # write your code here
        candidate = nums[0]
        count = 1
        
        for i in range(1, len(nums)):
            if nums[i] != candidate:
                count -= 1
            else:
                count += 1
                
            if count == 0:
                candidate = nums[i]
                count = 1
        
                
        return candidate