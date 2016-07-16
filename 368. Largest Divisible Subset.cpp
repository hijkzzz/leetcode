class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if (nums.size() < 2) return nums;

            // 从小到大排序
            sort(nums.begin(), nums.end());
            // 当前最大长度
            vector<int> dp(nums.size(), 1);
            // 记录上一个数的位置
            vector<int> s(nums.size(), -1);

            // 最大值的位置
            int mm = 0;
            for (int i = 1; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    // 判断是否可以继承 nums[j]
                    if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        s[i] = j;
                        if (dp[mm] < dp[i]) mm = i;
                    }
                }
            }

            // 递归查询结果
            vector<int> res;
            while (mm != -1) {
                res.push_back(nums[mm]);
                mm = s[mm];
            }

            return res;
        }
};
