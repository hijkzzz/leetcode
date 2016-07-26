class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> v;
            if(!root) return v;

            stack<TreeNode*> s;
            TreeNode* p = root;
            while(p || !s.empty()){
                //访问父节点、左子树
                if (p != NULL) {
                    v.push_back(p->val);
                    s.push(p);
                    p= p->left;
                } else {
                    //跳转到右子树
                    p = s.top();
                    s.pop();
                    p = p->right;
                }
            }
            return v;
        }
};
