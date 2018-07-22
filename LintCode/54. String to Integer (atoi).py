class Solution:
    """
    @param str: A string
    @return: An integer
    """
    def atoi(self, str):
        # write your code here
        if str is None or len(str) == 0:
            return 0
        
        i = 0
        sign = 1
        r = 0
        
        # 空格
        while str[i] == " ":
            i += 1
            
        # 正负号
        if str[i] == "-":
            sign = -1
            i += 1
        elif str[i] == "+":
            i += 1
        
        while i < len(str):
            if str[i] <= '9' and str[i] >= '0':
                r = r * 10 + ord(str[i]) - ord('0')
            else:
                break
            i += 1
            
        return max(min(r * sign, 2147483647), -2147483648)


if __name__ == "__main__":
    s = Solution()
    print(s.atoi('10'))