/**
 * 写出指数的二进制表达，例如13表达为二进制1101
 * 举例:10^1101 = 10^0001*10^0100*10^1000
 * 通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果
 */
class Solution {
    public:
        double Power(double base, int exponent) {
            int p = abs(exponent);
            double r = 1.0;
            while(p){
                if(p & 1) r *= base;
                base *= base;
                p >>= 1;
            }
            return exponent < 0 ? 1 / r : r;
        }
};
