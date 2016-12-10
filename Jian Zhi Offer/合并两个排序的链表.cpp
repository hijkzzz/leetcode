class Solution {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            ListNode* dummy = new ListNode(-1);
            ListNode* tail = dummy;
            while(pHead1 && pHead2) {
                if (pHead1->val < pHead2->val) {
                    tail->next = pHead1;
                    tail = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    tail->next = pHead2;
                    tail = pHead2;
                    pHead2 = pHead2->next;
                }
            }

            while(pHead1) {
                tail->next = pHead1;
                tail = pHead1;
                pHead1 = pHead1->next;
            }

            while(pHead2) {
                tail->next = pHead2;
                tail = pHead2;
                pHead2 = pHead2->next;
            }  
            return dummy->next;
        }
};
