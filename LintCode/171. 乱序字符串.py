class Solution:
    """
    @param strs: A list of strings
    @return: A list of strings
    """
    def anagrams(self, strs):
        # write your code here
        d = {}
        for s in strs:
            ss = self.hash(s)
            if ss in d:
                d[ss].append(s)
            else:
                d[ss] = [s]
        
        r = []
        for v in d.values():
            if len(v) > 1:
                r += list(v)
        return r
        
    def hash(self, s):
        base = ord('a')
        
        l = [0 for i in range(26)]
        for c in s:
            l[ord(c) - base] += 1
            
        r = ""
        for cc in l:
            r += "," + chr(cc)
        return r
        