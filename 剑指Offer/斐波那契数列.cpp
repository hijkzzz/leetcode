// 0 1 1 2 3 5 8
class Solution {
    public:
        int Fibonacci(int n) {
            int f0 = 0, f1 = 1;
            while (n--) {
                f1 = f0 + f1;
                f0 = f1 - f0;
            }
            return f0;
        }
};
