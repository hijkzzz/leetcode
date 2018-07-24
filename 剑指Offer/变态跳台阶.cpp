class Solution {
    public:
        int jumpFloorII(int number) {
            // 每个台阶都有跳与不跳两种情况
            return 1 << (number - 1);
        }
};
