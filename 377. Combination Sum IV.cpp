class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
	//  dp[i] += dp[i - num], num in nums
        for (int i = 1; i <= target; ++i) {
            for (auto num : nums) {
                if (num > i) break;
                dp[i] += dp[i - num];
            }
        }
        
        return dp[target];
    }
};