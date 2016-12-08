class Solution {
    public:
        int numDecodings(string s) {
            if (s.size() == 0) return 0;

            vector<int> dp(s.size() + 1, 0);
            dp[s.size()] = 1;
            // 最后剩一个 0 是不合理的情况
            dp[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;

            // 倒序比较容易处理 0
            for (int i = s.size() - 2; i >= 0; --i) {
                if (s[i] == '0') continue;
                dp[i] = stol(s.substr(i, 2)) < 27 ? dp[i + 1] + dp[i + 2] : dp[i + 1];
            }

            return dp[0];
        }
};
