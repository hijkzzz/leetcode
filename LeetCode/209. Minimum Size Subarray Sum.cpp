class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int start = 0, end = 0;
            int sum = 0;
            int minLen = INT_MAX;

            while (end < nums.size()) {
                if (sum < s) sum += nums[end++];

                while(sum >= s) {
                    if ((end - start) < minLen) minLen = end - start;
                    sum -= nums[start++];
                }
            }

            return minLen == INT_MAX ? 0 : minLen;
        }
};
