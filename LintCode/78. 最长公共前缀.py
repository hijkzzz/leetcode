class Solution:
    """
    @param strs: A list of strings
    @return: The longest common prefix
    """
    def longestCommonPrefix(self, strs):
        # write your code here
        if len(strs) < 1 or len(strs[0]) < 1 or strs[0][0] == "":
            return ""
        
        i = 0 
        
        while i < len(strs[0]):
            base = strs[0][i]
            for s in strs:
                if i >= len(s) or s[i] != base:
                    return strs[0][0:i]
            i += 1
            
        return strs[0]