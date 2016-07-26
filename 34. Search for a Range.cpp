/*
 * 二分查找攻略
 * http://www.cnblogs.com/wuyuegb2312/archive/2013/05/26/3090369.html
 */
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int f = binary_search_first(nums, target);
            int l = binary_search_last(nums, target);

            return {f, l};
        }

        int binary_search_first(vector<int>& nums, int target) {
            if (nums.size() == 0) return -1;

            int i = 0, j = nums.size() - 1;
            // == 会导致死循环
            while (i < j) {
                int mid = i + (j - i) / 2;

                if (nums[mid] < target) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            }

            return nums[i] == target ? i : -1;
        }

        int binary_search_last(vector<int>& nums, int target) {
            if (nums.size() == 0) return -1;

            int i = 0, j = nums.size() - 1;

            while (i < j) {
                //向右靠近
                int mid = i + (j - i) / 2 + ((j - i) & 1);

                if (nums[mid] <= target) {
                    i = mid;
                } else {
                    j = mid - 1;
                }
            }

            return nums[j] == target ? i : -1;
        }
};
