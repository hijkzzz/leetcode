class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """
    def maxProduct(self, nums):
        # write your code here
        # 访问到每个点的时候，以该点为子序列的末尾的乘积
        # 要么是该点本身，要么是该点乘以以前一点为末尾的序列
        # 注意乘积负负得正，故需要记录前面的最大最小值。
        
        maxx = nums[0]
        minn = nums[0]
        result = nums[0]
        
        for i in range(1, len(nums)):
            tempMaxx = maxx
            tempMinn = minn
            
            maxx = max(nums[i], nums[i] * tempMaxx, nums[i] * tempMinn)
            minn = min(nums[i], nums[i] * tempMaxx, nums[i] * tempMinn)
            result = max(maxx , result)
            
            
        return result