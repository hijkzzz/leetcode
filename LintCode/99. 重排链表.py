"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of the linked list.
    @return: nothing
    """
    def reorderList(self, head):
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        # 找到中间节点
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # 以中间节点为界，将链表断开，分成前后两部分
        # 断开的目的是方便链表翻转操作
        cur = slow.next
        slow.next = None
        # 单链表逆置
        while cur:
            temp = cur
            cur = cur.next
            temp.next = slow.next
            slow.next = temp
        # 再次断开成两个链表，合并
        second = slow.next
        slow.next = None
        pre = head
        while second:
            temp = second
            second = second.next
            temp.next = pre.next
            pre.next = temp
            pre = temp.next
        return head
        # write your code here
