"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param l1: ListNode l1 is the head of the linked list
    @param l2: ListNode l2 is the head of the linked list
    @return: ListNode head of linked list
    """
    def mergeTwoLists(self, l1, l2):
        # write your code here
        head = ListNode(None)
        tail = head
        
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                tail.next = l1
                tail = l1
                l1 = l1.next
            else:
                tail.next = l2
                tail = l2
                l2 = l2.next
                
        while l1 != None:
            tail.next = l1
            tail = l1
            l1 = l1.next
        
        while l2 != None:
            tail.next = l2
            tail = l2
            l2 = l2.next
            
        return head.next
