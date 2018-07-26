"""
Definition of ListNode

class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param head: n
    @return: The new head of reversed linked list.
    """
    def reverse(self, head):
        # write your code here
        head0 = ListNode(None, head)
        cur = head
        
        # 把下一个元素插入到首位置
        while cur != None and cur.next != None:
            third = cur.next.next
            cur.next.next = head0.next
            head0.next = cur.next
            cur.next = third
        
        return head0.next
