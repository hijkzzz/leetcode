class Solution:
    """
    @param n: Given a decimal number that is passed in as a string
    @return: A string
    """
    def binaryRepresentation(self, n):
        # write your code here
        i, d = n.split('.')
        i = int(i)
        d = float('0.' + d)
        
        integer = ""
        decimal = ""
        
        while d > 0:
            if len(decimal) >= 32:
                return "ERROR"
            
            d *= 2
            dd = int(d)
            decimal += str(dd)
            
            d -= dd
            
        if decimal != "":
            decimal = "." + decimal
            
        while i > 0:
            ii = i & 1
            integer = str(ii)  + integer
            
            i -= ii
            i >>= 1
            
        if integer == "":
            integer = "0"
            
        return integer + decimal