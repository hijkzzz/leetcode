class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result({vector<int>()});
        vector<int> current;
        for (int i = 1; i <= nums.size(); ++i) {
            helper(nums, i, current, 0, result);
        }
        return result;
    }

    void helper(vector<int>& nums, int length, vector<int> &current, int index, vector<vector<int>> &result) {
        if (index == length) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            // 同一位置不能选相同元素
            if(i > index && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            helper(nums, length, current, i + 1, result);
            current.pop_back();
        }
    }
};
