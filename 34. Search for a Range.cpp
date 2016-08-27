/*
 * 二分查找攻略
 * http://www.cnblogs.com/wuyuegb2312/archive/2013/05/26/3090369.html
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        // 查找下界
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        if (nums[l] == target) first = l;

        // 查找上界
        l = 0, r = nums.size() - 1;
        while (l < r) {
            // 当 nums[l] == nums[r] == target, +1 避免死循环
            int m = l + (r - l + 1) / 2;
            if (nums[m] <= target)
                l = m;
            else
                r = m - 1;
        }
        if (nums[l] == target) last = l;

        return {first, last};
    }
};
