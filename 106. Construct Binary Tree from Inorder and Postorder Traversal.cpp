class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size() == 0) return NULL;

            unordered_map<int, int> val2pos;
            for (int i = 0; i < inorder.size(); ++i) {
                val2pos.insert(make_pair(inorder[i] ,i));
            }

            return helper(0, 0, inorder.size(), inorder, postorder, val2pos);
        }

        TreeNode* helper(int p_start, int i_start, int len,
                vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& val2pos) {
            if (len == 0) return NULL;

            int father = postorder[p_start + len - 1];
            int i_pos = val2pos[father];

            // 根据中序排序，划分左、右子树
            TreeNode* new_node = new TreeNode(father);
            new_node->left = helper(p_start, i_start, i_pos - i_start, inorder, postorder, val2pos);
            new_node->right = helper(p_start + (i_pos - i_start), i_pos + 1, len - (i_pos - i_start) - 1, inorder, postorder, val2pos);

            return new_node;
        }
};
