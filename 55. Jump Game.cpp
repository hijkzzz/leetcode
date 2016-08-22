class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 最大能到达的位置
        int maxx = 0;
        for (int i = 0; i <= maxx && i < nums.size(); ++i) {
            if (i + nums[i] > maxx) maxx = i + nums[i];
        }
        return maxx >= nums.size() - 1;
    }
};
