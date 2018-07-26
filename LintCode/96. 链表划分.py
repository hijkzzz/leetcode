"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param head: The first node of linked list
    @param x: An integer
    @return: A ListNode
    """
    def partition(self, head, x):
        # write your code here
        small = ListNode(None)
        small_tail = small
        large = ListNode(None)
        large_tail = large
        
        while head != None:
            if head.val < x:
                small_tail.next = ListNode(head.val)
                small_tail = small_tail.next
            else:
                large_tail.next = ListNode(head.val)
                large_tail = large_tail.next
                
            head = head.next
        
        small_tail.next = large.next
        return small.next
        