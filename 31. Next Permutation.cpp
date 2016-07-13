/*
 *(1) 从后往前找一对递增序列 nums[i] < nums[i + 1]
 *(2) 从后往前找 nums[k] > nums[i]
 *(3) 交换 nums[k] nums[i]
 *(4) 将 nums[i] 后面的序列翻转
 *
 * 举例：
 *1 1 3 2 2
 *显然交换末尾的[2 1] 没有意义，只有用后面的大数换前面的小数才能增大
 *找到递增序列 1 3, 找到 nums[k] 2 > 1，交换 1 2 => 1 2 3 2 1
 *看似应该结束了， 但是末尾的 [3 2 1] 不是最小序列
 *由于 nums[i] 后面的序列为递减序列，所以翻转即为最小序列
 */

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if(nums.size() < 2) return;

            //查找增序
            int ii = nums.size() - 1;
            int i = ii - 1;
            while (i >= 0 && nums[i] >= nums[ii]) {
                --i;
                --ii;
            }

            //没找到增序
            if (i == -1) {
                reverse(nums.begin(), nums.end());
                return;
            }

            int k = nums.size() - 1;
            while (nums[i] >= nums[k])
                --k;
            swap(nums[i], nums[k]);

            reverse(nums.begin() + ii, nums.end());
        }
};
