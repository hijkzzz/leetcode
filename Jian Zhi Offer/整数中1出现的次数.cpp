/*
 * 从左至右统计每一位的1出现的次数	
 * 比如 2017，千位的1出现 1 * 1000 次，百位的1出现 2 * 100 次，十位的1出现 20 * 10 + 7 次，个位的1出现 202 次
 * 当前位 == 0，== 1，>= 2 时有不同的计算公式，需要分情况处理
 * 也可以用 (a + 8) / 10 * i + ( a % 10 == 1 ) * ( b + 1 ) 统一计算方式
 * 参考分析，https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
 */

class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n)
        {
            int count = 0;
            for (long long i = 1; i <= n; i *= 10) {
                // 分成两部分来分析
                int a = n / i;
                int b = n % i;
                // 分割点的数字
                int c = a % 10;

                if (c >= 2) {
                    count +=  (a / 10 + 1) * i;
                } else if (c == 1) {
                    count +=  a / 10 * i + (b + 1);
                } else {
                    count +=  a / 10 * i;
                }
            }
            return count;
        }
};
