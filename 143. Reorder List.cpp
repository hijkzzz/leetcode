class Solution {
    public:
        void reorderList(ListNode* head) {
            if (!head || !head->next) return;

            // 链表分成两半
            ListNode *slow = head, *fast = head, *prev = NULL;
            while (fast && fast->next) {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            prev->next = NULL;

            // 翻转后半部分
            ListNode *dummy = new ListNode(-1);
            dummy->next = slow;
            while (slow->next) {
                ListNode *temp = slow->next->next;
                slow->next->next = dummy->next;
                dummy->next = slow->next;
                slow->next = temp;
            }

            // 合并链表
            fast = head;
            slow = dummy->next;
            while (slow && fast) {
                ListNode *fast_next = fast->next, *slow_next = slow->next;
                fast->next = slow;
                slow->next = fast_next;

                prev = slow;
                fast = fast_next;
                slow = slow_next;
            }

            // slow.length > fast.length
            if (slow) prev->next = slow;
        }
};
