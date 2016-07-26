/*
 * 从 s[0] 开始找回文序列，如果找到 s[0] 到 s[i]，接着递归 s[i+1]，一直到达字符串末尾
 */
class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> tokens;
            bt(0, tokens, res, s);
            return res;
        }

        void bt(int k, vector<string> &tokens,vector<vector<string>> &res, const string &s) {
            if (k == s.size()) {
                res.push_back(tokens);
                return;
            }

            for (int i = k; i < s.size(); ++i) {
                if (isPalindrome(k, i, s)) {
                    tokens.push_back(s.substr(k, i - k + 1));
                    bt(i + 1, tokens, res, s);
                    tokens.pop_back();
                }
            }
        }

        bool isPalindrome( int i, int j, const string &s) {
            while (i < j) {
                if (s[i++] != s[j--]) return false;
            }
            return true;
        }
};
