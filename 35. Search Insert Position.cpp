class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找到第一个大于等于 target 的元素
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }

        // 如果不存在
        if (nums[l] < target) return l + 1;
        else return l;
    }
};
