class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int reched = 0;
            for (int i = 0 ; i < nums.size() - 1 && i <= reched; i++) {
                reched = max(reched, nums[i] + i);
            }
            return reched >= nums.size() - 1 ? true : false;
        }
};
