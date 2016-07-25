class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        // 最小值的位置
        int min_index = helper(nums);
	// 判断在哪一半，进行搜索
        if (target >= nums[min_index] && target <= nums.back())
            return find_target(nums, min_index, nums.size() - 1, target);
        else
            return find_target(nums, 0, min_index - 1, target);
    }
    
    // 搜索结果
    int find_target(vector<int>& nums, int i, int j, int target) {
        
        while (i <= j) {
            int m = i + (j - i) / 2;
            
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)    
                j = m - 1;
            else
                i = m + 1;
        }
        return -1;
    }
    
    // 找到最小的点
    // 画图分析一下就行了
    int helper(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            
            if (nums[m] > nums[j])
                i = m + 1;
            else if (nums[m] > nums[i])    
                j = m - 1;
            else
                j = m;
        }
        return i;
    }
};