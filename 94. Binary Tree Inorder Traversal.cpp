class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p != NULL) {
            if(p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                p= s.top();
                s.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
        return v;
    }
};
