class Solution {
    public:
        int jumpFloor(int number) {
            int f0 = 1;
            int f1 = 1;
            int f = 1;
            for (int i = 2; i <= number; ++i) {
                f = f0 + f1;
                f0 = f1;
                f1 = f;
            }
            return f;
        }
};
