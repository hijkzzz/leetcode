"""
Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
"""


class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    # 3次遍历：
    # 1）对每个结点进行复制，然后把复制出来的新节点接在原结点的next，也就是让链表变成一个重复链表，就是新旧更替；
    # 2）遍历每个旧node，把旧node的random的复制给新node的random，因为链表已经是新旧交替的。所以复制方法为：
    # node.next.random = node.random.next
    # 3）把新旧两个表拆开，返回新的表即可
    def copyRandomList(self, head):
        # write your code here
        if head == None:
            return None
        
        current = head
        while current != None:
            new = RandomListNode(current.label)
            new.next = current.next
            current.next = new
            current = current.next.next
                
        current = head
        while current != None:
            if current.random != None:
                new = current.next
                new.random = current.random.next
            current = current.next.next
        
        head0 = RandomListNode(None)
        tail0 = head0
        current = head
        while current != None:
            tail0.next = current.next
            tail0 = tail0.next
            current.next = current.next.next
            current = current.next
                
        return head0.next