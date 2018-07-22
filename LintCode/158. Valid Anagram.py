class Solution:
    """
    @param s: The first string
    @param t: The second string
    @return: true or false
    """
    def anagram(self, s, t):
        # write your code here
        if len(s) != len(t):
            return False
        
        alphabet = [0 for i in range(256)]
        for i in range(len(s)):
            alphabet[ord(s[i])] += 1
            alphabet[ord(t[i])] -= 1
            
        for count in alphabet:
            if count != 0:
                return False
        return True

            
