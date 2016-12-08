/*
 *  一位数共 10 个，两位 9 * 9 个，三位 9 * 9 * 8
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int answer = 10;
        int base = 9;
        int scale = 9;

        while (n-- > 1 && scale != 0) {
            base *= scale--;
            answer += base;
        }
        return answer;
    }
};
