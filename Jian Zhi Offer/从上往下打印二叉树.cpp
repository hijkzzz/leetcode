class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
		if (root == nullptr) return result;
        
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        return result;
    }
};
