class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size() - 2; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int three = nums.size() - 1;
            while ( second < three) {
                int sum = nums[first] + nums[second] + nums[three];
                if (abs(sum - target) < abs(closest - target)) closest = sum;

                if (sum == target) return sum;
                else if (sum > target) --three;
                else ++second;
            }
        }

        return closest;
    }
};
