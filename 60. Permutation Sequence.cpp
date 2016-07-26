class Solution {
    public:
        string getPermutation(int n, int k) {
            //这里改用链表效率高一点
            vector<int> v;
            int f = 1;
            for (int i = 1; i <= n; i++) {
                f *= i;
                v.push_back(i);
            }

            string res;
            //l = k - 1 很重要，因为进位机制的问题
            for (int i = 0, l = k - 1; i < n; i++) {
                //计算权值，即低位排序数
                f /= (n - i);
                //根据权值计算索引
                int index = (l / f);
                res += to_string(v[index]);
                v.erase(v.begin() + index);
                l -= index * f;
            }
            return res;
        }
};
