class Solution {
    public:
        vector<int> printListFromTailToHead(ListNode* head) {
            vector<int> result;   
            helper(result, head);
            return result;
        }

        void helper(vector<int> &result, ListNode* node) {
            if(!node) return;

            helper(result, node->next);
            result.push_back(node->val);
        }
};
