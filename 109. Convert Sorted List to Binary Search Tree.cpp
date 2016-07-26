class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if(head == NULL) return NULL;

            ListNode *fast = head;
            ListNode *slow = head;
            ListNode *prev = head;

            while(fast && fast->next){
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }

            TreeNode *root = new TreeNode(slow->val);
            prev->next = NULL;
            //只有一个元素
            if(slow == head) head = NULL;

            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);

            return root;
        }
};
