class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.size() < 2) return s;
            // 记录最大值
            int index;
            int length = 1;

            for (int i = 1; i < s.size(); ++i) {
                // 以 i 为中心展开
                int left = i - 1;
                int right = i + 1;
                int tmp = 1;
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    tmp +=2;
                    --left;
                    ++right;
                }
                if (tmp > length) {
                    length = tmp;
                    index = left + 1;
                }

                // 以 i - 1， i为中心展开
                left = i - 1;
                right = i;
                tmp = 0;
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    tmp +=2;
                    --left;
                    ++right;
                }
                if (tmp > length) {
                    length = tmp;
                    index = left + 1;
                }
            }
            return s.substr(index, length);
        }
};
