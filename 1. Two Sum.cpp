class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto itor = map.find(target - nums[i]);

            if(itor != map.end())
                return {(*itor).second, i};
            else map.insert(make_pair(nums[i], i));
        }
        return vector<int>();
    }
};
