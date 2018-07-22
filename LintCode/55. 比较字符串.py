class Solution:
    """
    @param A: A string
    @param B: A string
    @return: if string A contains all of the characters in B return true else return false
    """
    def compareStrings(self, A, B):
        # write your code here
        alphabet = [0 for i in range(256)]
        for a in A:
            alphabet[ord(a)] += 1
            
        for b in B:
            if alphabet[ord(b)] < 1:
                return False
            alphabet[ord(b)] -= 1
        return True