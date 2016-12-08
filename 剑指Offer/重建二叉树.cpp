class Solution {
    public:
        TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
            if (!pre.size() || !in.size()) return NULL;

            TreeNode *node = new TreeNode(pre[0]);
            int i = 0;
            for (; i < in.size(); ++i) {
                if (pre[0] == in[i]) break;
            }
            node->left = reConstructBinaryTree(vector<int>(pre.begin() + 1 ,pre.begin() + i + 1),
                    vector<int>(in.begin(), in.begin() + i));
            node->right = reConstructBinaryTree(vector<int>(pre.begin() + i + 1, pre.end()),
                    vector<int>(in.begin() + i + 1, in.end()));
            return node;
        }
};
