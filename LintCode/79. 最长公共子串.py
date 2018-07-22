class Solution:
    """
    @param A: A string
    @param B: A string
    @return: the length of the longest common substring.
    """

    def longestCommonSubstring(self, a, b):
        if len(a) == 0 or len(b) == 0:
            return 0

        # write your code here
        # 使用c[i,j] 表示 以 Xi 和 Yj 结尾的最长公共子串的长度
        r = 0
        c = [[0 for j in range(len(b) + 1)] for i in range(len(a) + 1)]
        for i in range(1, len(a) + 1):
            for j in range(1, len(b) + 1):
                if a[i - 1] == b[j - 1]:
                    c[i][j] = c[i - 1][j - 1] + 1
                else:
                    c[i][j] = 0

                r = max(c[i][j], r)
        return r