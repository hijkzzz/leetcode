class Solution {
    public:
        void Mirror(TreeNode *pRoot) {
            if (!pRoot) return;

            swap(pRoot->left, pRoot->right);
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
};
