"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    """
    @param head: the List
    @param k: rotate to the right k places
    @return: the list after rotation
    """
    def rotateRight(self, head, k):
        if head == None or head.next == None or k == 0:
            return head
        
        # write your code here
        slow = head
        fast = head 
        while k > 0:
            if fast == None:
                fast = head
            fast = fast.next
            k -= 1
        
        # 正好转回来了
        if fast == None:
            return head
        
        while fast.next != None:
            slow = slow.next
            fast = fast.next
        
        head0 = slow.next
        slow.next = None
        fast.next = head
        
        return head0