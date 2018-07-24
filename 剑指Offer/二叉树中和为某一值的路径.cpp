class Solution {
    public:
        vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
        {
            vector<vector<int>> result;
            vector<int> path;
            if(!root)
                return result;

            helper(root, expectNumber, path, result);
            return result;
        }

        void helper(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &result)
        {
            path.push_back(root->val);
            if(root->val == target && !root->left && !root->right){
                result.push_back(path);
                path.pop_back();
                return;
            }

            if (root->left)
                helper(root->left, target - root->val, path, result);
            if (root->right)
                helper(root->right, target - root->val, path, result);
            path.pop_back();
        }
};
