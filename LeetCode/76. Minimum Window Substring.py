class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        need, missing = collections.Counter(t), len(t)
        i = I = J = 0
        
        for j, c in enumerate(s, 1):
            missing -= need[c] > 0
            need[c] -= 1
            
            if missing == 0:
                while i < j and need[s[i]] < 0:
                    need[s[i]] += 1
                    i += 1
                if J == 0 or j - i <= J - I:
                    I, J = i, j
                    
        return s[I:J]