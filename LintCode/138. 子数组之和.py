class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number
             and the index of the last number
    """
    def subarraySum(self, nums):
        # write your code here
        d = {0: -1}
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            if sum in d:
                return [d[sum] + 1, i] 
            d[sum] = i
            
        return []

if __name__ == "__main__":
    s = Solution()
    data = [-3,1,2,-3,4]
    print(s.subarraySum(data))