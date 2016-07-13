class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if(!head || !head->next) return head;

            ListNode* fast = head,
                * slow = head,
                * prev = head;

            while (fast != NULL && fast->next != NULL) {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            prev->next = NULL;

            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(slow);
            return merge(l1, l2);
        }

        ListNode* merge(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* last = dummy;

            while (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    last->next = l1;
                    last = l1;
                    l1 = l1->next;
                } else {
                    last->next = l2;
                    last = l2;
                    l2 = l2->next;
                }
            }

            while (l1 != NULL) {
                last->next = l1;
                last = l1;
                l1 = l1->next;
            }

            while (l2 != NULL) {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }

            return dummy->next;
        }
};
