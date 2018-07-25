class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def numTrees(self, n):
        # write your code here
        # 因为左子树小于根节点/右子树大于根节点
        # f(0) = 1
        # f(1) = 1
        # f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-2)*f(1) + f(n-1)*f(0)
        
        if n == 0:
            return 1
        
        f = [0 for i in range(n + 1)]
        f[0] = 1
        f[1] = 1
        
        for i in range(2, n + 1):
            for k in range(0, i):
                f[i] += f[k] * f[i - k - 1]
        
        return f[n]