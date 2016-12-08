class Solution {
public:
    // dp[i], which means the maxSubArray for A[0:i] which must has A[i] as the end element
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int maxx = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};
