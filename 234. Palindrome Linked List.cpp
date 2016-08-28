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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 旋转后半部分
        ListNode* dummy = new ListNode(-1);
        dummy->next = fast ? slow->next : slow;

        ListNode* current = dummy->next;
        while (current && current->next) {
            ListNode* temp = current->next->next;
            current->next->next = dummy->next;
            dummy->next = current->next;
            current->next = temp;
        }

        // 比较，注意链表两部分没有断开，所以用 dummy 作为循环结束条件
        dummy = dummy->next;
        while (dummy) {
            if (head->val != dummy->val) return false;
            head = head->next;
            dummy = dummy->next;
        }
        return true;
    }
};
