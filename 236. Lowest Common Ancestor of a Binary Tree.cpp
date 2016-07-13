/*
 * 分别搜索两个节点，记录路径
 * 然后查找分开点，即最近的祖先
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL || p == NULL || q == NULL) return NULL;

            vector<TreeNode*> pathp(1, root);
            vector<TreeNode*> pathq(1, root);

            getPath(pathp, root, p);
            getPath(pathq, root, q);

            int i = 0;
            for (; i < pathq.size() && i < pathp.size(); i++) {
                if (pathp[i] != pathq[i]) break;
            }

            return pathq[i - 1];
        }

        bool getPath(vector<TreeNode*>& path, TreeNode* current, TreeNode* dest) {
            if (current == dest) {
                return true;
            }

            if (current->left) {
                path.push_back(current->left);
                if(getPath(path, current->left, dest)) return true;
                path.pop_back();
            }

            if (current->right) {
                path.push_back(current->right);
                if (getPath(path, current->right, dest)) return true;
                path.pop_back();
            }

            return false;
        }
};
