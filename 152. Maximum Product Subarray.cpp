class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 0) return 0;

            int pre_min = nums[0];
            int pre_max = nums[0];
            int result = nums[0];

            for (int i = 1; i < nums.size(); ++i) {
                int temp = pre_min;
                pre_min = min(min(pre_min * nums[i], pre_max * nums[i]), nums[i]);
                // 当前最大值一定是 nums[i]，pre_max *nums[i]，pre_min * nums[i] 中的一个
                pre_max = max(max(pre_max * nums[i], temp * nums[i]), nums[i]);
                result = max(result, pre_max);
            }
            return result;
        }
};
