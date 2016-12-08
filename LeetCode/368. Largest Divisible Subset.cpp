class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        sort(nums.begin(), nums.end());

        int mm = 0;
        vector<int> dp(nums.size(), 1);
        vector<int> s(nums.size(), -1);
        // dp[i] 以 nums[i] 为最大数的最长子集长度
        // dp[i] = max(dp[j] + 1) -- nums[i] % nums[j] == 0
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    s[i] = j;
                    if (dp[mm] < dp[i]) mm = i;
                }
            }
        }

        // 取出结果
        vector<int> result;
        while(mm != -1) {
            result.push_back(nums[mm]);
            mm = s[mm];
        }
        return result;
    }
};
