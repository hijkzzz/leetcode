/*
 * 最简单的方法，一直减直到 dividend < divisor
 * 减的次数就是最终解
 *
 * 但是我们可以利用位运算做一些优化
 * 如果 dividend >= divisor ，就让 divisor 左移
 * 直到减不下，减去 divisor，记下 divisor 的左移次数
 * 接下来恢复 divisor 到初始大小，继续上一步骤
 */
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == INT_MIN && divisor == -1 || divisor == 0)
                return INT_MAX;

            bool minus = dividend < 0 ^ divisor < 0;
            long long dividend2 = labs(dividend);
            long long divisor2  = labs(divisor);

            int cnt = 0;
            while (dividend2 >= divisor2) {
                long long temp = divisor2;
                int multiple = 1; // 倍数
                while (dividend2 >= (temp << 1)) {
                    multiple <<= 1;
                    temp <<= 1;
                }
                dividend2 -= temp;
                cnt += multiple;
            }

            return minus ? -cnt : cnt;
        }
};
