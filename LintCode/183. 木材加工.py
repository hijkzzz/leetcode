class Solution:
    """
    @param L: Given n pieces of wood with length L[i]
    @param k: An integer
    @return: The maximum length of the small pieces
    
    https://blog.csdn.net/gzy13269561397/article/details/50810882
    """
    def woodCut(self, L, k):
        # write your code here
        # 确定可能的区间
        i = 1
        j = sum(L) // k
        
        # 二分搜索
        while i <= j:
            m = (i + j) // 2
            
            if self.judge(L, k, m):
                i = m + 1
            else:
                j = m - 1
                
        return i if self.judge(L, k, i) else i - 1
            
    
    def judge(self, L, k, cutLen):
        summ = sum(map(lambda x : x // cutLen, L))
        return True if summ >= k else False