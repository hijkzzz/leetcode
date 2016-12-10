class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next) return pHead;
        
		ListNode* dummy = new ListNode(-1);
        dummy->next = pHead;  
        ListNode* current = pHead;
        while(current && current->next) {
			ListNode *temp = current->next;
            current->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    } 
};
