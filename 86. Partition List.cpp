class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* result = new ListNode(0);
            ListNode* dummy = new ListNode(0);
            dummy->next = head;

            ListNode* last = result;
            ListNode* prev = dummy;
            ListNode* p = head;
            while(p){
                ListNode* next = p->next;
                //插入新链表
                if(p->val < x){
                    last->next = p;
                    p->next = NULL;
                    last = p;
                    //从原链表删除
                    prev->next = next;
                    p = next;
                }
                else{
                    prev = p;
                    p = next;
                }
            }

            //连接两个链表
            last->next = dummy->next;
            return result->next;
        }
};
