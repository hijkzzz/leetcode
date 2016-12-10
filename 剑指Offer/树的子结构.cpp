class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if (pRoot2 == nullptr || pRoot1 == nullptr) 
            return false;
        return isSubtree(pRoot1, pRoot2) 
            || HasSubtree(pRoot1->left, pRoot2) 
            || HasSubtree(pRoot1->right, pRoot2);
        
    }
    
    bool isSubtree(TreeNode* pRoot1 , TreeNode* pRoot2){
        if(pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr)
            return false;
        return pRoot1->val == pRoot2->val 
            && isSubtree(pRoot1->left, pRoot2->left) 
            && isSubtree(pRoot1->right, pRoot2->right);
    }
};
