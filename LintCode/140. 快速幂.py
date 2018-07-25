class Solution:
    """
    @param a: A 32bit integer
    @param b: A 32bit integer
    @param n: A 32bit integer
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        
        # (a*b)%p = (a%p * b%p)%p
        # Even
        # (a^n/2 * a^n/2)%b = (a^n/2%b * a^n/2%b) %b
        # Odd
        # (a^n% b * a%b)%b; --> a^n%b come from the above formula
        
        if n == 0:
            return 1 % b
        elif n == 1:
            return a % b
        
        if n & 1 == 0:
            return (self.fastPower(a, b, n // 2) ** 2) % b
        else:
            return (self.fastPower(a, b, n - 1) * a % b) % b
