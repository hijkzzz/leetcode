// https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
class Solution {
    public:
        int rectCover(int number) {
            if (number < 1) return 0;
            if (number == 1) return 1;
            if (number == 2) return 2;

            return rectCover(number - 1) + rectCover(number - 2);
        }
};
