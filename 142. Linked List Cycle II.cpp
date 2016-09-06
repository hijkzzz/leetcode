/*
 * a + b + N(c + b) = 2a + 2b
 * a = N(c + b) - b
 * 设 d 为环长
 * a = Nd - b
 * a = (N - 1)d + c
 * 
 * http://www.jianshu.com/p/ce7f035daf74
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        auto fast = head;
        auto slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                auto p = head;
                auto q = fast;
                while (p != q)
                {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};