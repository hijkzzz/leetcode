class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2 || k == 0) return false;
        unordered_map<int, int> map;
        map[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            if(map.find(nums[i]) != map.end()) return true;
            //删除范围 k 以前的元素
            if(i >= k) map.erase(nums[i - k]);
            map[nums[i]] = 1;
        }
        return false;
    }
};
