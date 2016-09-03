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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //测量链表长度
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;

        while(pA != NULL){
            pA = pA->next;
            lenA++;
        }
        while(pB != NULL){
            pB = pB->next;
            lenB++;
        }

        //对齐到交点的距离
        if(lenA > lenB){
            for(int i =0; i < lenA - lenB; i++){
                headA = headA->next;
            }
        }
        else{
            for(int i =0; i < lenB - lenA; i++){
                headB = headB->next;
            }
        }

        //找到交点
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
