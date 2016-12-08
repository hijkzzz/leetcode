class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> result;
        helper(1, k, n, current, result);
        return result;
    }

    void helper(int i, int k, int target, vector<int> &current, vector<vector<int>> &result) {
        if (k == 0 && target == 0) {
            result.push_back(current);
            return;
        }

        for ( ; i <= 9; ++i) {
            if (target < i) break;
            current.push_back(i);
            helper(i + 1, k - 1, target - i, current, result);
            current.pop_back();
        }
    }
};
