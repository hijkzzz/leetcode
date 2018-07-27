"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: The root of binary tree.
    @return: True if the binary tree is BST, or false
    """
    def isValidBST(self, root):
        # write your code here
        return self.recursion(root, float('-inf'), float('inf'))
        
    def recursion(self, root, minn, maxx):
        if root is None:
            return True
            
        if root.val <= minn or root.val >= maxx:
            return False
            
        return self.recursion(root.left, minn, root.val) and \
            self.recursion(root.right, root.val, maxx)