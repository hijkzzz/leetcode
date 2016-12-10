class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            if(pListHead == nullptr || k == 0) return nullptr;

            ListNode* head = pListHead;
            while(--k > 0) {
                if (!head->next) 
                    return nullptr;
                else
                    head = head->next;
            }

            while(head->next) {
                head = head->next;
                pListHead = pListHead->next;
            }
            return pListHead;
        }
};
