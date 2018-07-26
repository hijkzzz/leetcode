class Solution:
    """
    @param nums: A list of non negative integers
    @return: A string

    排序的思想 放在前面大则排在前面
    """
    def largestNumber(self, nums):
        # write your code here
        for i in range(1, len(nums)):
            for j in range(len(nums) - 1, i - 1, -1):
                if int(str(nums[j]) + str(nums[j - 1])) > int(str(nums[j - 1]) + str(nums[j])):
                    nums[j], nums[j - 1] = nums[j - 1], nums[j]
        
        
        return "0" if nums[0] == 0 else "".join(map(lambda x : str(x), nums))
                