"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm 
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    """
    def serialize(self, root):
        # write your code here
        if root is None:
            return '#'
            
        r = []
        q = [root]
        while len(q) > 0:
            front = q[0]
            q = q[1:]
            if front is None:
                r.append('#')
            else:
                r.append(str(front.val))
                q.append(front.left)
                q.append(front.right)
                
        return ",".join(r)

    """
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in 
    "serialize" method.
    """
    def deserialize(self, data):
        # write your code here
        data = data.split(',')
        
        if data[0] == '#':
            return None
        
        root = TreeNode(int(data[0]))
        q = [root]
        data = data[1:]
        
        i = 0
        while i < len(data):
            node = q[0]
            q = q[1:]
            if data[i] == '#':
                node.left = None
            else:
                node.left = TreeNode(int(data[i]))
                q.append(node.left)
                
            if data[i + 1] == '#':
                node.right = None
            else:
                node.right = TreeNode(int(data[i + 1]))
                q.append(node.right)
            
            i += 2
            
        return root
            
        
        
