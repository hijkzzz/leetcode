class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> combination;
            sort(candidates.begin(), candidates.end());
            combinationSum(candidates, target, result, combination, 0);
            return result;
        }

        void combinationSum(vector<int> &candidates, int target,
                vector<vector<int>> &res, vector<int> &combination, int begin) {
            if(!target){
                res.push_back(combination);
            }

            for(int i = begin; i < candidates.size() && candidates[i] <= target; ++i){
                combination.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], res, combination, i);
                combination.pop_back();
            }
        }
};
