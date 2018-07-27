"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param: root: The root of the binary search tree.
    @param: node: insert this node into the binary search tree
    @return: The root of the new binary search tree.
    """
    def insertNode(self, root, node):
        # write your code here
        if root is None:
            return node
        
        current = root
        while True:
            if node.val < current.val:
                if current.left is None:
                     current.left = node
                     break
                else:
                    current = current.left
            else:
                if current.right is None:
                     current.right = node
                     break
                else:
                    current = current.right
        
        return root