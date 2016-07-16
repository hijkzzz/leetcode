class Solution {
    public:
        string multiply(string num1, string num2) {
            // 从低位到高位排序
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());

            // 计算结果
            vector<int> res(num1.size() + num2.size(), 0);

            // 相乘并累加，暂不处理进位
            for (int i = 0; i < num1.size(); i++) {
                for (int j = 0; j < num2.size(); j++) {
                    res[i + j] += (num1[i] - '0') * (num2[j] - '0');
                }
            }

            // 进位处理
            for (int i = 0, c = 0; i < res.size(); i++) {
                res[i] += c;
                c = res[i] / 10;
                res[i] %= 10;
            }

            // 输出结果
            string num3;
            int i = res.size() - 1;
            while (i >= 0 && res[i] == 0)
                i--;

            if (i == -1) num3 = "0";
            else
                while (i >= 0) {
                    num3 += ('0' + res[i]);
                    --i;
                }

            return num3;
        }
};
