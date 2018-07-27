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
    @return: True if this Binary tree is Balanced, or false.
    """
    def isBalanced(self, root):
        # write your code here
        balanced, depth = self.recursion(root)
        return balanced
        
        
    def recursion(self, root):
        if root == None:
            return True, 0
        
        leftBalanced, leftDepth = self.recursion(root.left)
        rightBalanced, rightDepth = self.recursion(root.right)
        
        return leftBalanced and rightBalanced and abs(leftDepth - rightDepth) <= 1, \
            max(leftDepth, rightDepth) + 1