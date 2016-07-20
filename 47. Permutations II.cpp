class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            bt(0, nums, result);
            return result;
        }

        void bt(int k, vector<int> nums, vector<vector<int>>& result) {
            if (k == nums.size() - 1) {
                result.push_back(nums);
            }

            for (int i = k; i < nums.size(); ++i) {
                if (i != k && nums[k] == nums[i]) continue;
                // 交换后不恢复，以保证子序列有序
                // 1 2 3 4 5
                // 2 1 3 4 5
                // 3 1 2 4 5
                // 4 1 2 3 5
                // 5 1 2 3 4
                swap(nums[k], nums[i]);
                bt(k + 1, nums, result);
            }
        }
};
