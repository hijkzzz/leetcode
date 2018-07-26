"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param head: The first node of linked list.
    @param n: An integer
    @return: The head of linked list.
    """
    def removeNthFromEnd(self, head, n):
        # write your code here
        dummy = ListNode(None, head)
        
        fast = head
        slow = dummy
        
        while n > 0:
            fast = fast.next
            n -= 1
        
        while fast != None:
            slow = slow.next
            fast = fast.next
        
        slow.next = slow.next.next
        return dummy.next