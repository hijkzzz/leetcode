"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next

Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param: head: The first node of linked list.
    @return: a tree node
    """
    def sortedListToBST(self, head):
        # write your code here
        return self.recursion(head, None)
    
            
    def recursion(self, head, end):
        if head == end:
            return None
            
        slow = head
        fast = head
        while fast != end and fast.next != end:
            slow = slow.next
            fast = fast.next.next
        
        root = TreeNode(slow.val)
        root.left = self.recursion(head, slow)
        root.right = self.recursion(slow.next, end)
        return root
        