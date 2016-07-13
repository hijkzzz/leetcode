class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

        //新建一个链表
        ListNode* dummy = new ListNode(INT_MIN);
        //链表尾
        ListNode* last = dummy;
        ListNode* p = head;

        while(p){
            //备份下一个指针
            ListNode* next = p->next;
            if(p->val < last->val){
                ListNode* temp = dummy;
                while(temp->next->val < p->val)
                    temp = temp->next;
                //插到中间
                ListNode* nn = temp->next;
                temp->next = p;
                p->next = nn;
            }
            //插到末尾
            else{
                last->next = p;
                p->next = NULL;
                last = p;
            }
            p = next;
        }

        return dummy->next;
    }
};
