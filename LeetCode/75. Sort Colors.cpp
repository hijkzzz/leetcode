class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        int q = nums.size() - 1;
        for (int i = 0; i <= q;) {
            if (nums[i] == 0)
                swap(nums[p++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[q--], nums[i]);
            else
                ++i;
        }
    }
};
