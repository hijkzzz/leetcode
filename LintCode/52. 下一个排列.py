class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers
    """
    def nextPermutation(self, nums):
        # write your code here
        # 从低位向高位（从右向左）找第一个递减的数：s[i]<s[i+1]
        # 如果不存在，则表明该permutation已经最大，next permutation为当前序列的逆序
        # 在s[i+1:n-1]中找一个j，使s[j]>s[i]，swap(s[i],s[j])
        # 将s[i+1:n-1]逆序

        # 解释：
        # 我们要找出下一个比当前序列大的序列
        # 第一步是从右至左找出一对 (i, j) 使得s[i] < s[j]
        # 然后交换它们的值（把一个大数换到前面去了）
        # 最后逆序即是从小到大排序
        
        if len(nums) == 1:
            return nums
        
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        
        if i == -1:
            nums.reverse()
            return nums
        
        j = len(nums) - 1
        while j > i and nums[j] <= nums[i]:
            j -= 1 
            
        nums[i], nums[j] = nums[j], nums[i]
        
        r = nums[i + 1:]
        r.reverse()
        return nums[:i + 1] + r