class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            //其实就是求高位相同部分
            //因为其它位必定有 0 1 的进位
            int cnt = 0;
            while (m != n) {
                m >>= 1;
                n >>= 1;
                ++cnt;
            }
            return m << cnt;
        }
};
