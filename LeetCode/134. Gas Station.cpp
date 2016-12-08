/*
 *如果数组整体和 >= 0
 *必然可以找到一个元素
 *从这个元素出发，绕数组一圈，累加和一直是出于非负状态
 *
 *举例：
 *[A ... B ... C  ... D]
 *假设 [A to D] 的整体和 >= 0
 *(1) 开始由 A 向后累加，可惜到达 B 时累加和变成负数
 *(2) 重新由 B + 1 向后累加，不巧到达 C 时累加和又变成负数
 *(3) 恰好 [C + 1 to D] 的累加和一直为正（如果不恰好，可以继续开展新的累加，一定能找到“恰好”的情况）
 *
 *因为 [A to B - 1] 和 [B to C - 1] 的累加和一直为正
 *且由假设有 [C + 1 to D] + [A to B] + [B + 1 to C] == [A to D] >= 0
 *所以 [C + 1 to C] 的累加和一直为正
 */
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            if (!gas.size() || !cost.size() || gas.size() != cost.size())
                return -1;
            int total = 0, sum = 0, start = 0;
            for (int i = 0; i < gas.size(); ++i) {
                int diff = gas[i] - cost[i];
                sum += diff;

                //开始新的累加
                if (sum < 0) {
                    start = i + 1;
                    sum = 0;
                }

                total += diff;
            }
            return total >= 0 ? start : -1;
        }
};
