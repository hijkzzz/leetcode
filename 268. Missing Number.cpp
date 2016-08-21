class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // 如果不 miss 有 n + 1 个元素
        int sum = n * (n + 1)/2;

        for (const auto &a : nums) {
            sum -= a;
        }
        return sum;
    }
};
