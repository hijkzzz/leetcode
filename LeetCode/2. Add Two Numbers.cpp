class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(INT_MIN);
            ListNode* p = dummy;

            while (l1 && l2) {
                p->next = new ListNode(l1->val + l2->val);
                p = p->next;
                l1  = l1->next;
                l2  = l2->next;
            }

            while (l1) {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }

            while (l2) {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }

            // 进位
            p = dummy;
            int c = 0;
            while (p->next) {
                p->next->val += c;
                c = p->next->val / 10;
                p->next->val %= 10;

                p = p->next;
            }

            if (c > 0) p->next = new ListNode(c);

            return dummy->next;
        }
};
