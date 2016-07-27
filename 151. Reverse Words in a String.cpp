class Solution {
    public:
        void reverseWords(string &s) {
            if (s.size() == 0) return;

            // 去前导 后导 0
            int index = 0;
            while (index < s.size() && s[index] == ' ') ++index;
            int left = index;
            index = s.size() - 1;
            while (index >= 0 && s[index] == ' ') --index;
            int right = index;

            if (left > right) {
                s = "";
                return;
            }

            // 去连续的空格
            for (int i = left; i <= right;) {
                if (i > left && s[i - 1] == ' ' && s[i] == ' ') {
                    s.erase(i, 1);
                    --right;
                } else
                    ++i;
            }

            // 翻转单词
            for (int i = left; i < right;) {
                int j = i;
                while (j <= right && s[j] != ' ') ++j;
                // reverse 函数是左闭右开的
                reverse(s.begin() + i, s.begin() + j);
                // 跳过空格
                i = j + 1;
            }

            s = s.substr(left, right - left + 1);
            reverse(s.begin(), s.end());
        }
};
