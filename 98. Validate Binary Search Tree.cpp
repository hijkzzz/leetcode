class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return helper(INT_MIN, INT_MAX, root);
        }

        // mn mx 分别表示可以取的最小值和最大值
        bool helper(long long mn, long long mx, TreeNode* root) {
            if (root == nullptr) return true;
            if (root->val < mn || root->val > mx) return false;

            return helper(mn, (long long)root->val - 1, root->left) && helper((long long)root->val + 1, mx, root->right);
        }
};
