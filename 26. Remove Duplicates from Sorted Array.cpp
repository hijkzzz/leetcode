class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() < 2) return nums.size();

            //p指向下一个地址
            int p = 1;
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] != nums[p - 1]){
                    nums[p++] = nums[i];
                }
            }
            return p;
        }
};
