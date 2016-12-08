/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode* dummy = new ListNode(0),* backup = dummy;
        dummy->next = head;
        while(head != NULL){
            if(head->val == val){
                dummy->next = head->next;
                head = dummy->next;
            }
            else{
                head = head->next;
                dummy = dummy->next;
            }

        }
        return backup->next;
    }
};
