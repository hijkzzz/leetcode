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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummy = new ListNode(0);
       dummy->next = head;

       ListNode* fast = dummy, * slow = dummy;
       //fast 移动到 n 的前一个节点
       for(int i = 0; i <= n; i++){
           fast = fast->next;
       }

       while(fast != NULL){
           slow = slow->next;
           fast = fast->next;
       }
       slow->next = slow->next->next;
       return dummy->next;
    }
};
