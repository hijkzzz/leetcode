class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *current = head;
        while (current && current->next) {
            ListNode *temp = current->next;
            current->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};
