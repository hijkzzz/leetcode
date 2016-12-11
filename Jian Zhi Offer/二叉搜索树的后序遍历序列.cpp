class Solution {
    public:
        bool VerifySquenceOfBST(vector<int> a) {
            if(!a.size()) return false;
            return judge(a);
        }

        // 左子树 < 根 < 右子树  
        bool judge(vector<int> sequence) {
            if (sequence.size() <= 1) return true;

            int parent = sequence[sequence.size() - 1];
            // 找到左右子树序列分界点
            int i = 0;
            for (;i < sequence.size() - 1 && sequence[i] < parent; ++i);
            // 检查右子树序列
            int j = i;
            for (;j < sequence.size() - 1; ++j)
                if (sequence[j] <= parent) 
                    return false;
            // 递归判断子树 
            return judge(vector<int>(sequence.begin(), sequence.begin() + i))
                && judge(vector<int>(sequence.begin() + i, sequence.end() - 1));
        }
};
