class Solution:
    """
    @param A: A positive integer which has N digits, A is a string
    @param k: Remove k digits
    @return: A string

    每次都删除第一个峰值
    """
    def DeleteDigits(self, A, k):
        # write your code here
        l = list(A)
        while k > 0:
            for i in range(len(l)):
                if i == len(l) - 1:
                    l = l[:i]
                    break
                elif l[i] > l[i + 1]:
                    l = l[:i] + l[i + 1:]
                    break
            k -= 1
        
        while l[0] == '0':
            l = l[1:]
            
        return "".join(l)