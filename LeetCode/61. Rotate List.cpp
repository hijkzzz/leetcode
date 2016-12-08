class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == nullptr) return head;

            // 变成循环链表
            ListNode* p = head;
            int len = 1;
            while (p->next != nullptr) {
                p = p->next;
                ++len;
            }
            p->next = head;

            // 平移头指针
            k %= len;
            int xx = len - k;
            while (xx > 1){
                head = head->next;
                --xx;
            }
            p = head->next;

            // 设置尾指针
            head->next = nullptr;
            return p;
        }
};
