"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    def levelOrder(self, root):
        # write your code here
        if root == None:
            return []
            
        r = []
        q = [root]
        qq = []
        cur = []
        while len(q) > 0:
            front = q[0]
            q = q[1:]
            cur.append(front.val)
            
            if front.left:
                qq.append(front.left)
            if front.right:
                qq.append(front.right)
            
            # 进入下一层
            if len(q) == 0:
                q = qq
                qq = []
                
                r.append(cur)
                cur = []
                
        return r