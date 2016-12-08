class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() == 0) return ranges;

        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == (nums[j - 1] + 1)) ++j;

            if (i < (j - 1))
                ranges.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            else
                ranges.push_back(to_string(nums[i]));
            i = j;
        }
        return ranges;
    }
};
