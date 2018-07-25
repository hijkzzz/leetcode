class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        for (int pos = i; pos <= j; ++pos)
            n &= ~( 1 << pos);
        m <<= i;
        return n | m;
    }
};