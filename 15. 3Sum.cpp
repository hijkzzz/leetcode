class Solution {
    public:
        // -2 -2 -2 0 0 0 1 1 1
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            if (nums.size() < 3) return result;

            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size();) {
                int target = -nums[i];

                int front = i + 1, rear = nums.size() - 1;
                while (front < rear) {
                    int sum = nums[front] + nums[rear];
                    if (sum < target) ++front;
                    else if (sum > target) --rear;
                    else {
                        vector<int> temp = {nums[i], nums[front], nums[rear]};
                        result.push_back(temp);
                        // 跳过重复元素
                        while (front < rear && nums[front] == temp[1]) ++front;
                        while (front < rear && nums[rear] == temp[2]) --rear;
                    }
                }
                // 跳过重复元素
                while (i < nums.size() && nums[i] == -target) ++i;
            }

            return result;
        }
};
