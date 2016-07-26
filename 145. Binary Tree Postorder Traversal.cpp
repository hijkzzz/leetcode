class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> v;
            if(root == NULL) return v;

            stack<pair<TreeNode*, char>> s;
            TreeNode* p = root;
            while(p || !s.empty()){
                if(p != NULL){
                    s.push(make_pair(p, 'L'));
                    p = p->left;
                } else {
                    pair<TreeNode*, char> temp = s.top();
                    if (temp.second == 'L') {
                        temp.second = 'R';
                        p = temp.first->right;
                    } else {
                        s.pop();
                        v.push_back(temp.first->val);
                    }
                }
            }
            return v;
        }
};
