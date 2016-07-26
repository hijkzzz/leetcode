class Solution {
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            vector<bool> f(s.size() + 1, false);
            f[0] = true;

            for (int i = 1; i <= s.size(); ++i) {
                //遍历分割点
                for (int j = 0; j < i; ++j) {
                    if (f[j] &&
                            wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                        f[i] = true;
                        break;
                    }
                }
            }

            return f[s.size()];
        }
};
